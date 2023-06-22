// 28_다형성5.cpp
#include <iostream>
using namespace std;

// 1. 부모의 함수가 가상함수 일때만, 오버라이딩 해야 합니다.
//  => 부모의 포인터나 참조를 통해 이용할 경우,
//     자식의 함수가 호출되지 않는 문제를 해결할 수 있습니다.

// 2. 부모의 함수가 가상함수이면, 자식이 오버라이딩한 함수도 가상함수입니다.

// 3. C++11, override
//  - 자식이 정의한 함수가 부모에 제공되지 않을 때, 컴파일 오류!
//  - 부모가 제공하는 함수가 가상함수가 아닐 때, 컴파일 오류!

class Car {
public:
    virtual void Start() const { cout << "Car Start" << endl; }
};

class Sedan : public Car {
public:
    // virtual void Start() {}
    // virtual void Start() const override {}
    void Start() const override { cout << "Car Start" << endl; }
};

int main()
{
}
