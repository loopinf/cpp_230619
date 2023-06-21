// 18_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 제공하지 않으면,
//    컴파일러가 아무일도 수행하지 않는 인자 없는 생성자를 자동으로 제공합니다.
//          "trivial 생성자"
//    : Point() {} => 기본 생성자

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.

// 3. 생성자는 오버로딩이 가능합니다.
//   => 객체를 초기화하는 다양한 방법을 제공할 수 있습니다.

// 4. 기본 생성자를 제공하는 것이 편리할 때가 많습니다.

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    Point()
    {
        x = 0;
        y = 0;
    }
};

int main()
{
    Point pt2;

    // Point pt; // Point()
    Point pt(10, 20);
}
