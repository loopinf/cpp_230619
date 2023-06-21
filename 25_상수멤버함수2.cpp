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

public:
    Rect(int x, int y)
        : leftTop(x, y)
    {
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

void foo(const Rect& rect)
{
    const Point& pt = rect.GetLeftTop();
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
