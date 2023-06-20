// 21_초기화리스트2.cpp
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
};

// 초기화 리스트를 반드시 제공해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 멤버

class Rect {
    Point leftTop;
    Point rightBottom;

public:
    // 컴파일러가 제공하는 생성자 형태
#if 0
    Rect(): leftTop(), rightBottom() {}
#endif

    Rect()
        : leftTop(10, 20) // Point(int, int)
        , rightBottom(30, 40) // Point(int, int)
    {
    }
};

int main()
{
    Rect r;
}
