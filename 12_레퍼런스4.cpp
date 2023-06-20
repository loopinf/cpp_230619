// 12_레퍼런스4.cpp
#include <iostream>
using namespace std;

// C++ 레퍼런스
// 1) lvalue reference
//   - lvalue만 참조할 수 있습니다.

// 2) rvalue reference, C++11
//   - rvalue만 참조할 수 있습니다.

// lvalue: 왼쪽에 올수 있는 것
//         특정 메모리 위치를 참조하는 표현식입니다.
//         lvalue는 메모리 주소가 할당되어 있으므로, & 연산자를 이용해서
//         주소를 얻을 수 있습니다.

// rvalue: 왼쪽에 올수 없는 것
//         일회용 임시 대상체를 참조하는 표현식입니다.
//         생성된 위치에서 조작할 수 없고, 소멸됩니다.
//         주소를 얻을 수 없습니다.

#if 0
int main()
{
    int a;
    a = 3;
    // a: lvalue
    // 3: rvalue

    const int c = 10;

    // c = 42;
}
#endif

#if 0
template <typename T>
void Print(const T& a)
{
    // ...
}

// const lvalue reference
// => lvalue, rvalue 모두 참조할 수 있습니다.

struct User { };

int main()
{
    Print(42); // Print(const int&)

    User user;
    Print(user); // Print(const User&)

    Print(User());
}
#endif

// C++98/03
void foo(const int& r)
{
    cout << "const lvalue reference" << endl;
}

void foo(int&& rr)
{
    cout << "rvalue reference" << endl;
}
// 1) move - 소유권 이동
// 2) forward - 퍼펙트 포워딩

int main()
{
    foo(10); // rvalue

    int n = 10;
    foo(n); // lvalue

    // n은 lvalue이기 때문에 lvalue reference 이용해야 합니다.
    int& r1 = n;
    // int& r2 = 10; // 오류!

    // rvalue reference는 rvalue만 참조 가능합니다.
    // int&& rr1 = n; // 오류!

    int&& rr2 = 10;
    rr2 = 100;
}
