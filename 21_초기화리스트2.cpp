// 21_초기화리스트2.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int a = 0, int b = 0)
        : x(a)
        , y(b)
    {
    }
};

// 초기화 리스트를 반드시 제공해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 멤버
// > 멤버 객체의 초기화 순서는 멤버가 선언된 순서에 의해 결정됩니다.
//  주의사항
//   - 초기화리스트에서 멤버를 초기화할 때,
//     멤버가 선언된 순서대로 초기화해야 합니다.
#if 0
class Rect {
    Point leftTop;
    Point rightBottom;

public:
    // 컴파일러가 제공하는 생성자 형태
#if 0
    Rect(): leftTop(), rightBottom() {}
#endif

#if 0
    // 아래처럼 사용하면, 오해의 소지가 있습니다.
    Rect()
        : rightBottom(10, 20) // Point(int, int)
        , leftTop(30, 40) // Point(int, int)
    {
    }
#endif

    Rect()
        : leftTop(10, 20) // Point(int, int)
        , rightBottom(30, 40) // Point(int, int)
    {
    }

    Rect(int x1, int y1, int x2, int y2)
        : leftTop(x1, y1)
        , rightBottom(x2, y2)
    {
    }
};

int main()
{
    Rect r; // 1) Rect::Rect() 생성자 호출
}
#endif

#include <string>

class Sample {
    string name;

public:
    Sample(string s)
        : name(s)
    {
        cout << "Sample(): " << name << endl;
    }

    ~Sample()
    {
        cout << "~Sample(): " << name << endl;
    }
};

class Rect {
    Sample s1;
    Sample s2;

public:
    Rect()
        : s2("B")
        , s1("A")
    {
    }
};

int main()
{
    Rect r;
}
