// 25_상수멤버함수2.cpp
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

    void Print() const { cout << x << ", " << y << endl; }

    void Set(int a, int b)
    {
        x = a;
        y = b;
    }
};

class Rect {
    Point leftTop;

    mutable string cache;
    // 객체의 상수성과 관계없는 멤버 데이터
    // => 상수 멤버 함수 안에서 수정이 가능해야 합니다.

public:
    Rect(int x, int y)
        : leftTop(x, y)
    {
    }

    void Print() const
    {
        cache = "캐시된 데이터";
    }

    // const Point leftTop;
    const Point& GetLeftTop() const
    {
        return leftTop;
    }

    // 해결 방법
    // - 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공할 수 있습니다.
    Point& GetLeftTop()
    {
        return leftTop;
    }
};

// 상수 멤버 함수만 제공할 경우
//        Point p  ----> 상수 멤버 함수
//  const Point p  ----> 상수 멤버 함수
//  const Point* p ----> 상수 멤버 함수
//  const Point& p ----> 상수 멤버 함수

// 비상수 멤버 함수만 제공할 경우
//        Point p  ----> 비상수 멤버 함수
//  const Point p  ----> X
//  const Point* p ----> X
//  const Point& p ----> X

// 상수 멤버 함수 / 비상수 멤버 함수
//        Point p  ----> 비상수 멤버 함수
//  const Point p  ----> 상수 멤버 함수
//  const Point* p ----> 상수 멤버 함수
//  const Point& p ----> 상수 멤버 함수

void foo(const Rect& rect)
{
    const Point& pt = rect.GetLeftTop();
    // pt.Set(10, 20);
    pt.Print();
}

int main()
{

    Rect r(100, 200);
    foo(r);

    Point& pt = r.GetLeftTop();
    pt.Set(10, 20);
    pt.Print();
}
