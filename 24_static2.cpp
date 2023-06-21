// 24_static2.cpp
#include <iostream>
using namespace std;

class Car {
    int color;
    static int cnt; // 클래스 상태

public:
    Car()
    {
        ++cnt;
    }

    ~Car() { --cnt; }

    // 객체를 통해서만 호출이 가능합니다.
    // int GetCount() { return cnt; }

    // 정적 멤버 함수 / 클래스 메소드
    // > 일반 함수와 동일하지만, 클래스의 접근 제어를 사용할 수 있습니다.
    //   객체를 생성하지 않아도 호출이 가능합니다.
    //   객체의 주소, this가 전달되지 않습니다
    static int GetCount() { return Car::cnt; }
};

int Car::cnt = 0;

int main()
{
    // 정적 멤버 함수를 사용하는 방법
    // 1. 클래스
    cout << Car::GetCount() << endl;

    // 2. 객체
    Car car;
    cout << car.GetCount() << endl;
}
