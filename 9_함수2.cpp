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

int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
}
