// 32_연산자오버로딩.cpp
#include <iostream>
using namespace std;

class Complex {
    int re;
    int im;

public:
    Complex(int r, int i)
        : re(r)
        , im(i)
    {
    }

    // Complex Add(const Complex& rhs)
    // Complex operator+(const Complex& rhs)
    // {
    //     return Complex(re + rhs.re, im + rhs.im);
    // }

    void Print() const { cout << re << " + " << im << "i" << endl; }

    // friend Complex Add(const Complex& lhs, const Complex& rhs);
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
};

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

// 연산자 오버로딩
// => 객체를 대상으로 연산자를 사용할 경우,
//    약속된 이름의 멤버 함수 또는 일반 함수를 통해
//    수행됩니다.

int main()
{
    Complex c1(10, 3);
    c1.Print();

    Complex c2(5, 3);
    c2.Print();

    // 복소수의 합의 연산을 제공하고 싶습니다.
    Complex result = c1 + c2;
    // 1) 멤버 함수
    //               c1.operator+(c2);
    // 2) 일반 함수
    //               operator+(c1, c2);

    // Complex result = c1.Add(c2);
    // Complex result = Add(c1, c2);
    result.Print();
}
