// 9_함수7.cpp
#include <iostream>
using namespace std;

// int add(int a, int b) { return a + b; }

// C++11, 함수를 만드는 새로운 방법이 도입되었습니다.
// - Trailing Return Type

auto add(int a, int b) -> int { return a + b; }

// 1) 기존 함수의 반환 타입을 표시할 때의 문제점을 해결할 수 있습니다.
// => typedef

// int (*foo())[3]

// typedef int (*PARR3)[3];
// PARR3 foo()

auto foo() -> int (*)[3]
{
    static int x[3] = { 10, 20, 30 };
    return &x; // int (*)[3]
}

// int (*goo())(int, int)

// using FP = int (*)(int, int);
// FP goo()

auto goo() -> int (*)(int, int)
{
    return add; // int (*)(int, int)
}

int main()
{
    cout << add(10, 20) << endl;
}
