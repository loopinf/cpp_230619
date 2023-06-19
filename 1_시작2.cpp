// 1_시작2.cpp

// 1. C++ 확장자
//  .cpp / .cc / .cxx / ...

// 2. C++ 컴파일러
//  1) Windows, Microsoft Visual C/C++ Compiler, MSVC
//  2) Linux, GNU C/C++ Compiler, GCC
//  3) LLVM Compiler

// 3. C++ 표준
//  1) C++98/C++03
//  2) C++11/C++14, 2차 표준안 => Modern C++
//  3) C++17/C++20

// 4. C++은 C를 포함합니다.
//  > C의 표준과 C++ 안에서의 C의 표준은 다릅니다.

#if 0
#include <stdio.h>

// void foo(void) { }
// void goo() { }

int main()
{
    // foo(42);
    // goo(42);

    printf("Hello, C\n");

    // return 0;
    // : 작성하지 않을 경우, 컴파일러가 자동으로 return 0; 삽입합니다.
}
#endif

// C++ 표준입출력
#include <iostream>
// 확장자를 생략하는 경우가 많습니다.

int main()
{
    std::cout << "Hello, C++" << std::endl;
}
