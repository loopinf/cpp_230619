// 24_static.cpp
#include <iostream>
using namespace std;

// 1. 멤버 변수는 객체마다 존재합니다.
// 2. 전역 변수는 정보 은닉이 불가능합니다.
//  => 정적 멤버 변수

class Car {
    static int cnt; // 정적 멤버 변수 선언
    int color;

public:
    Car()
    {
        ++cnt;
    }

    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

// 정적 멤버 변수 정의 => 소스 코드
int Car::cnt = 0;

int main()
{
    cout << sizeof(Car) << endl;

    Car c1, c2;
    Car cars[5];

    // cout << c1.cnt << endl;

    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;
}

#if 0
int cnt = 0;

class Car {

public:
    Car()
    {
        ++cnt;
    }

    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c1, c2;
    Car cars[5];

    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;
}
#endif

#if 0
class Car {
    int cnt;

public:
    Car()
        : cnt(0)
    {
        ++cnt;
    }

    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c1, c2;
    cout << c1.GetCount() << endl;
    cout << c2.GetCount() << endl;
}
#endif
