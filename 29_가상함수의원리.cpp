// 29_가상함수의원리
#include <iostream>
using namespace std;

// 1. 클래스 가상 함수가 1개라도 존재하면,
//    객체의 크기가 가상 함수 테이블을 가르키는 포인터 크기(8바이트)만큼 늘어납니다.
// 2. 클래스가 가지고 있는 가상 함수의 개수 만큼의 테이블의
//    메모리가 추가적으로 필요합니다.

class Animal {
    int color;
    int age;

public:
    virtual void Go() const { }
};

class Dog : public Animal {
    int speed;
};

int main()
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Dog) << endl;
}
