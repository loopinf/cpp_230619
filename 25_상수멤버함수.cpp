// 25_상수멤버함수.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

    // 상수 멤버 함수
    // 1. 상수 멤버 함수 안에서 멤버 데이터를 상수 취급합니다.
    //   int x -> const int x;
    //   int y -> const int y;

    // 2. 멤버 함수를 만들 때,
    //    멤버 함수 내부에서 멤버 데이터를 변경하지 않는 경우
    //    반드시 상수 멤버 함수로 만들어야 합니다.
    void Print() const
    {
        // x = 10;
        // y = 20;

        cout << x << ", " << y << endl;
    }
};

void foo(const Point& pt)
{
    // const& 참조되는 객체는 상수 멤버 함수만 호출이 가능합니다.
    pt.Print();
}

int main()
{
    Point pt(10, 20);
    pt.Print();

    foo(pt);

    const Point* p = &pt; // 상수 멤버 함수만 호출 가능
    p->Print();

    const Point c(100, 200); // 상수 객체도 상수 멤버 함수만 호출 가능
    c.Print();

    // 상수 참조도 상수 멤버 함수만 호출 가능
    const Point& r = pt;
    r.Print();
}
