// 32_연산자오버로딩8.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 복사 생성자를 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 복사 생성자를 제공합니다.

// 2. 사용자가 대입 연산자를 제공하지 않으면,
//    컴파일러는 멤버를 복사하는 대입 연산자를 제공합니다.

// 3. 멤버 함수를 통해서만 연산재 재정의가 가능합니다.

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

    Point(const Point& rhs)
        : x(rhs.x)
        , y(rhs.y)
    {
        cout << "Point(const Point&)" << endl;
    }

    Point& operator=(const Point& rhs)
    {
        cout << "operator=(const Point&)" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this;
    }

    // friend 함수 선언/구현
    friend ostream& operator<<(ostream& os, const Point& pt)
    {
        return os << pt.x << ", " << pt.y;
    }
};

int main()
{
    int a, b;
    // (b = 10) = 100;
    cout << b << endl;

    Point pt(10, 20);
    cout << pt << endl;

    Point other = pt; // 복사 생성자

    other = pt; // 대입 연산자
    cout << other << endl;
}
