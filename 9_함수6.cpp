// 9_함수6.cpp
#include <iostream>
using namespace std;

// 정수에 대해서 최대 공약수를 구하는 함수
int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

// 위의 함수를 실수를 사용할 경우를 금지하고 싶습니다.

// 금지하는 방법
// 1) 구현을 제공하지 않고, 선언만 합니다.
// int gcd(double a, double b);
/*
Undefined symbols for architecture arm64:
  "gcd(double, double)", referenced from:
      _main in 9_함수6-90ce9e.o
*/
// 문제의 원인을 파악하기도 어렵고, 의도를 전달하기도
// 어렵습니다.

// 2) C++11, delete function
// > 함수 호출 금지 문법
/*
9_함수6.cpp:32:13: error: call to deleted function 'gcd'
    cout << gcd(3.14, 5.5) << endl;
*/
int gcd(double a, double b) = delete;

int main()
{
    cout << gcd(10, 3) << endl;
    cout << gcd(15, 3) << endl;

    // cout << gcd(3.14, 5.5) << endl;
}
