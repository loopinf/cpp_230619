// 18_생성자2.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
public:
    Point() { cout << "Point()" << endl; }
    Point(int a, int b) { cout << "Point(int, int)" << endl; }

    ~Point() { cout << "~Point()" << endl; }
};

// 1. malloc을 통해 객체를 생성하였을 때, 생성자는 호출되지 않습니다.
// 2. new를 통해 객체를 생성하였을 때, 생성자가 호출됩니다.
// 2. free를 통해 객체를 파괴하였을 때, 소멸자가 호출되지 않지만,
//    delete를 통해 객체를 파괴하면, 소멸자가 호출됩니다.

// new 연산
// 1) 동적 메모리 할당
// 2) 객체라면, 생성자 호출

// delete
// 1) 객체라면, 소멸자 호출
// 2) 동적 메모리 해지

int main()
{
    // Point* pt1 = static_cast<Point*>(malloc(sizeof(Point)));
    // free(pt1);

    Point* pt2 = new Point; // Point()
    delete pt2;

    Point* pt3 = new Point(10, 20); // Point(int, int)
    delete pt3;

    Point* pt4 = new Point { 10, 20 }; // Point(int, int)
    delete pt4;

    Point* pt5 = new Point[3];
    delete[] pt5;

    Point* pt6 = new Point[3] { Point(), Point(10, 20), Point() };
    delete[] pt6;

    Point* pt7 = new Point[3] { {}, { 10, 20 }, { 10, 20 } };
    delete[] pt7;
}
