// 15_nullptr.cpp
#include <iostream>
using namespace std;

// 1. 정수 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.
// #define NULL (void*)0

#if 1
int main()
{
    // int* p = 0;
    int* p = NULL;

    bool b1 = true;
    bool b2 = false;
    // 표현식의 결과로서 이용됩니다.

    // - 참: 1, 거짓: 0
    // - 참: 0이 아닌값, 거짓: 0
    if (p) {
        cout << *p << endl;
    }
}
#endif

// 2. NULL 문제점
//  => 정수 타입인지 포인터 타입인지 모호합니다.
//    : 타입 안정성이 없습니다.

// 3. C++11, NULL을 대체하는 nullptr 도입하였습니다.

void foo(int n) { cout << "int" << endl; }
void foo(int* p) { cout << "int*" << endl; }

// 4. nullptr의 정확한 타입은 nullptr_t 타입입니다.
//  => 포인터 타입으로의 암묵적인 변환이 허용됩니다.
//     bool 타입으로의 암묵적인 변환이 허용됩니다.

int main()
{
    int* p = nullptr;

    foo(0);
    foo(nullptr);

    // if (nullptr) { // 거짓으로 판단됩니다.
    if (p) {
        cout << *p << endl;
    }
}
