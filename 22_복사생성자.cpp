// 22_복사생성자.cpp
#include <iostream>
using namespace std;

// 멤버 데이터의 이름 규칙
// 1) m_x
// 2) mX
// 3) x_
// 4) _x => 표준에서 사용하는 방식이므로, 충돌의 위험성을
//          가집니다.

class Point {
    int x_;
    int y_;

public:
    Point(int x, int y)
        : x_(x)
        , y_(y)
    {
    }

    Point(const Point& rhs)
        : x_(rhs.x_)
        , y_(rhs.y_)
    {
        cout << "Point(const Point&)" << endl;
    }

    void Print()
    {
        cout << x_ << ", " << y_ << endl;
    }

    void SetX(int x)
    {
        // 반드시 this를 명시해야 합니다.
        // this->x = x;
        x_ = x;
    }
};

// 1. 사용자가 생성자를 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 기본 생성자를 제공합니다.

// 2. 사용자가 생성자를 제공하면, 기본 생성자를 제공하지 않습니다.

// 3. 사용자가 복사 생성자를 제공하지 않으면,
//    컴파일러는 멤버 복사를 수행하는 복사 생성자를 제공합니다.
//  => 자신과 동일한 타입을 인자를 받는 생성자
//      Point(const Point&)

class Sample { };
// Sample s;
// Sample s2 = s;

class Sample2 {
public:
    Sample2(const Sample&) { }
};
// 복사 생성자만 제공할 경우, 복사 생성자도 생성자이기 때문에
// 컴파일러는 기본 생성자를 제공하지 않습니다.

int main()
{
    Point pt1 { 10, 20 };
    pt1.Print();

    // Point pt2;

    // 복사 생성자가 호출되는 코드
    // Point pt2(pt1);
    // Point pt2 { pt1 };
    // Point pt2 = pt1;
    Point pt2 = { pt1 };
    pt2.Print();
}
