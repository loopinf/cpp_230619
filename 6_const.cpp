// 6_const.cpp
#include <iostream>
using namespace std;

// 1. C++에서 const는 반드시 초기화가 필요합니다.

// 2. C에서 const는 상수 표현식이 아닙니다.
//   C++에서 const는 상수 표현식이 될 수 있습니다.

// 3. 상수
//  - 컴파일 타임 상수, 상수 표현식
//   : 값을 변경할 수 없습니다.
//     값을 읽기 위해서는 메모리에 접근하지 않습니다.

//  - 런타임 상수
//   : 런타임 상수의 값을 변경할 수 없습니다.
//     값을 읽기 위해서는 메모리에 접근해야 합니다.

// 4. C의 상수는 런타임 상수입니다.
//    상수 표현식이 아니므로, 배열의 크기를 지정하는 목적으로 사용할 수 없습니다.

// 5. C++의 상수는 컴파일 타임 상수가 될 수 있습니다.
//    컴파일 타임 상수의 경우, 배열의 크기로 지정할 수 있습니다.

const int C = 100;
//   C: 소스 코드, 기본 external linkage
// C++: 헤더 파일, 기본 internal linkage

// 6. C++11, constexpr
//  => 상수 표현식을 통해, 컴파일 타임 상수를 표현할 수 있습니다.

int main()
{
    constexpr int c1 = 100; // 컴파일 타임 상수
    printf("%d\n", c1);

    int n = 42;
    // constexpr int c2 = n; // 오류, 런타임 상수
    const int c2 = n;
    printf("%d\n", c2);
}
