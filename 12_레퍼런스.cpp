// 12_레퍼런스.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int n = 42;

    int* p = &n;

    *p = 100;
    cout << *p << endl;
    cout << n << endl;
}
#endif

// 레퍼런스: 기존 메모리에 새로운 이름(별명)을 부여합니다.
//  > 반드시 초기화가 필요합니다.
int main()
{
    int n = 42;

    int* p = NULL;
    // int& r2; // 허용되지 않습니다. 컴파일 오류!
    //          // 널 레퍼런스는 제공되지 않습니다.

    int& r = n;

    r = 100;
    cout << r << endl;
    cout << n << endl;
}
