// 32_연산자오버로딩4.cpp
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

    int GetX() const { return x; }
    int GetY() const { return y; }

    void SetX(int a) { x = a; }
    void SetY(int b) { y = b; }
};

ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.GetX() << ", " << pt.GetY();
    // os.operator<<(pt.GetX()).operator<<(", ")
    //   .operator<<(pt.GetY()) => os
}

istream& operator>>(istream& is, Point& pt)
{
    int x, y;
    is >> x >> y;
    pt.SetX(x);
    pt.SetY(y);

    return is;
}

int main()
{
    Point pt(10, 20);

    cin >> pt;
    // operator>>(cin, pt)

    cout << pt << endl;
    // operator<<(cout, pt)
}
