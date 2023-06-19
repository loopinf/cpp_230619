// 4_변수3.cpp
#include <iostream>
using namespace std;

// Uniform Initialization
// => Preventing Narrow
//  실수 타입이 정수 타입으로의 암묵적인 변환을 허용하지 않습니다.
//  더 큰 표현 범위의 정수를 작은 표현 범위의 정수로의 암묵적인 변환을
//  허용하지 않습니다.

int main()
{
    double d = 3.14;
    // int n1 = d;
    // int n1(d);

    // int n1 = { (int)d };
    int n1 { (int)d };

    long long l = 10000000000000LL;
    // int n2 = l;

    int n2 = { (int)l };

    cout << n1 << endl;
    cout << n2 << endl;
}
