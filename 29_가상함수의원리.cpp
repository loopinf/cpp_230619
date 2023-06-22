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
    virtual void Cry() const { }
    virtual void Hoo() const { }

    void foo() { }
};

class Dog : public Animal {
    int speed;
};

void foo() { }

int main()
{
    printf("%p\n", foo);
    printf("%p\n", &foo);

    // cout << sizeof(Animal) << endl;
    // cout << sizeof(Dog) << endl;

    // 멤버 함수는 반드시 &를 사용해야 합니다.
    printf("%p\n", &Animal::Go);
    printf("%p\n", &Animal::Cry);
    printf("%p\n", &Animal::Hoo);
    //----

    printf("%p\n", &Animal::foo);
}
