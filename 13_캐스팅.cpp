// 13_캐스팅.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc

// 캐스팅 연산자: 명시적으로 타입 간의 변환을 위해 사용합니다.

void print(char* str)
{
    // ..
}

// C의 캐스팅의 문제점
// - 용도와 목적이 달라도, 동일한 형태를 가지고 있기 때문에
//   파악하기 어렵다.
// => C++은 용도와 목적에 따라 4가지의 캐스팅 연산자를 제공합니다.
//  1) static_cast
//    : 가장 기본적인 C++ 캐스팅 연산자 입니다.
//      컴파일 타임에 캐스팅을 수행하기 때문에, 이름이 static_cast 입니다.
//     1) 실수 타입을 정수 타입으로의 변환
//     2) 더 넓은 표현범위의 정수를 작은 범위의 정수로 캐스팅할 때
//     3) void*를 구체적인 포인터타입으로의 변환
//     4) 다운 캐스팅
//        무조건 성공하기 때문에 실패할 확률이 없는 경우에만 사용해야 합니다.

//  2) reinterpret_cast
//    : 메모리를 재해석하는 용도로 사용합니다.
//    => 위험한 캐스팅 연산자입니다.

//  3) const_cast
//    => const / volatile
//    : 메모리의 (상수성/휘발성)을 제거하는 목적으로 사용합니다.
//      메모리를 수정하기 위함이 아니라, 타입의 불일치 문제를 해결하기 위해
//      사용해야 합니다.
//      상수 메모리를 수정하는 행위는 미정의 동작을 야기합니다.

//  4) dynamic_cast
//    - 잘못된 타입에 대해서 수행될 경우, nullptr을 반환합니다.
//      다운 캐스팅에서 타입을 실행시간에 체크해서 캐스팅을 수행할 수
//      있습니다.

int main()
{
    double d = 3.14;
    int n1 { static_cast<int>(d) };

    long long ll = 42LL;
    int n2 { static_cast<int>(ll) };

    // C++은 void*를 구체적인 포인터 타입으로의 암묵적인 변환을 허용하지
    // 않습니다.
    int* p = static_cast<int*>(malloc(sizeof(int)));

    //--------

    // 메모리 재해석
    int x = 0x12345678;
    // unsigned char* pc = static_cast<unsigned char*>(&x); // 오류!
    unsigned char* pc = reinterpret_cast<unsigned char*>(&x);
    printf("%x %x %x %x\n", pc[0], pc[1], pc[2], pc[3]);

    // long long* pl = reinterpret_cast<long long*>(&x);
    // *pl = 42LL; // 미정의 동작

    // 타입 불일치 문제(const)
    const char* str = "hello";
    // char* ps = static_cast<char*>(str); // 오류!
    // char* ps = reinterpret_cast<char*>(str); // 오류!
    char* ps = const_cast<char*>(str);
    print(const_cast<char*>(str)); // const char* -> char*

    volatile int* pv = &x;
    int* pp = const_cast<int*>(pv);
}

#if 0
int main()
{
    double d = 3.14;
    int n1 { (int)d };

    long long ll = 42LL;
    int n2 { (int)ll };

    // C++은 void*를 구체적인 포인터 타입으로의 암묵적인 변환을 허용하지
    // 않습니다.
    int* p = (int*)malloc(sizeof(int));

    // 메모리 재해석
    int x = 0x12345678;
    unsigned char* pc = (unsigned char*)&x;
    printf("%x %x %x %x\n", pc[0], pc[1], pc[2], pc[3]);

    // 타입 불일치 문제(const)
    const char* str = "hello";
    print((char*)str); // const char* -> char*
}
#endif
