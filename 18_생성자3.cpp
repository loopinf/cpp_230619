// 18_생성자3.cpp
#include <iostream>
using namespace std;

class Point {
public:
    Point() { cout << "Point()" << endl; }
    ~Point() { cout << "~Point()" << endl; }
};

// 1. 멤버 데이터의 생성자가 먼저 호출되고, 객체의 생성자가 수행됩니다.
// 2. 객체의 소멸자가 수행되고, 멤버 데이터의 소멸자가 호출됩니다.

class Rect {
    Point leftTop;
    Point rightBottom;

public:
    Rect() { cout << "Rect()" << endl; }
    ~Rect() { cout << "~Rect()" << endl; }
};

int main()
{
    Rect r;
    // 1.     leftTop - Point()
    // 2. rightBottom - Point()
    // 3. Rect()

} // ~Rect()
//   ~Point() - rightBottom
//   ~Point() - leftTop
