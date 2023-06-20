// 9_함수2.cpp
#include <iostream>
using namespace std;

// https://devdocs.io/

// C는 함수의 인자 타입이 다를 경우,
// 함수의 이름을 다르게 만듭니다.
#if 0
int squarei(int x) { return x * x; }
double squaref(double x) { return x * x; }

int main()
{
    cout << squarei(10) << endl;
    cout << squaref(3.14) << endl;
}
#endif

// C++은 함수의 인자 정보가 다른 경우,
// 동일한 이름의 함수를 여러개 만들 수 있습니다.
// > 함수 오버로딩(overloading)

int square(int x) { return x * x; } // __Z3squarei
double square(double x) { return x * x; } // __Z3squared
long long square(long long x) { return x * x; } // __Z3squareL

// 원리
// 1) 함수의 이름을 지을 때,
//    인자 정보를 사용합니다. => 네임 맹글링(Mangling)
//    foo()    => __Z3foov
//    foo(int) => __Z3fooi
// 2) 함수의 반환 타입은 이름에 포함되지 않습니다.
//    함수의 인자가 동일하고 반환타입만 다를 경우,
//    오버로딩은 불가능합니다.

// 3) extern "C"  => 네임 맹글링을 수행하지 않습니다.
//   1) 오버로딩이 불가능합니다.
//   2) C의 프로그램에서 C++의 함수를 호출하거나,
//    C++ 프로그램에서 C의 함수를 호출하는 목적으로 사용할 수 있습니다.

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
}
