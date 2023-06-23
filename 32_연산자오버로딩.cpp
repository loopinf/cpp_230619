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

Complex operator+(int n, const Complex& rhs)
{
    return Complex(0, 0);
}

Complex operator+(const Complex& rhs, int n)
{
    return n + rhs;
}

// 연산자 오버로딩
// => 객체를 대상으로 연산자를 사용할 경우,
//    약속된 이름의 멤버 함수 또는 일반 함수를 통해
//    수행됩니다.

// 1) 연산자 우선 순위는 동일합니다.
//    a + (b * c);
//    => a.operator+(b.operator*(c))

//    a * b + c
//    => a.operator*(b).operator+(c)

// 2) 피연산자의 개수도 변경되지 않습니다.
//    a + b
//      a.operator+(b)
//      operator+(a, b)

// 3) 새로운 연산자를 제공할 수 없습니다.
// 4) 연산자 오버로딩이 불가능한 연산자도 있습니다.
//   1) ::(범위 연산자)
//   2) . (접근 연산자)
//   3) .* (멤버 함수 포인터 참조 연산자)
//   4) 삼항 연산자
//      (expr) ? (statement) : (statement)

// 5) 반드시 피 연산자 중에 하나는 사용자 정의 타입이어야 합니다.
//    Complex c1;
//    c1 + 10;
//     Complex operator+(const Complex& lhs, int n) => OK
//     int operator+(int a, int b)  => NO!

// 6) 반드시 멤버 함수를 통해서만 제공되어야 하는 연산자가 있습니다.
//  => 클래스의 제작자만 추가할 수 있는 연산자 재정의입니다.
//   1) 대입 연산자
//      a = b;
//   2) 함수 호출 연산자 => 함수 객체
//      a();
//   3) 임의 접근 연산자
//      a[0], a[1]
//   4) ->
//      멤버 포인터 연산자
//   5) *
//      포인터 참조 연산자

int main()
{
    Complex c1(10, 3);
    c1.Print();

    // Complex r = c1 + 10;
    Complex r = 10 + c1;
    // c1.operator+(10);
    r.Print();

    Complex c2(5, 3);
    c2.Print();

    // 복소수의 합의 연산을 제공하고 싶습니다.
    Complex result = c1 + c2;
    // 1) 멤버 함수 => 클래스의 제작자만 추가할 수 있습니다.
    //               c1.operator+(c2);
    // 2) 일반 함수
    //               operator+(c1, c2);

    // Complex result = c1.Add(c2);
    // Complex result = Add(c1, c2);

    result.Print();
}
