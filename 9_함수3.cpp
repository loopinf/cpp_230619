// 9_함수3.cpp
#include <iostream>
using namespace std;

// 함수 오버로딩 주의 사항
// 1) 함수의 인자 정보가 동일할 경우,
//    함수 오버로딩이 불가능합니다.
// int foo() { }
// void foo() { }

// 2) 파라미터 기본값과 함께 사용할 경우, 주의해야 합니다.
void foo(int n = 0) { }
void foo() { }

int main()
{
    // foo();
}
