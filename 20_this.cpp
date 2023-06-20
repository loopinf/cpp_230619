// 20_this.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    // 멤버 함수
    // => 객체의 주소가 첫번째 인자 this로 암묵적으로 전달됩니다.
    // => thiscall

    // void Set(Point* this, int a, int b)
    void Set(int a, int b)
    {
        cout << "this: " << this << endl;

        x = a;
        // this->x = a;
        y = b;
        // this->y = b;
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt1, pt2;
    cout << "&pt1: " << &pt1 << endl;
    pt1.Set(10, 20); // Point::Set(&pt1, 10, 20)
    pt1.Print();

    cout << "&pt2: " << &pt2 << endl;
    pt2.Set(100, 200); // Point::Set(&pt2, 100, 200)
    pt2.Print();
}
