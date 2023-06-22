// 27_상속6.cpp
#include <iostream>
using namespace std;

// protected 생성자 의도
//  : 부모 클래스 객체는 생성할 수 없지만,
//    자식 클래스 객체는 생성할 수 있도록 하겠다.
//  "Animal을 추상 타입으로 사용하겠다." 의도!

class Animal {
    int age;

protected:
    Animal(int n = 0)
        : age(n)
    {
    }
};

class Dog : public Animal {
public:
    Dog()
        : Animal()
    {
    }
};
class Cat : public Animal { };

int main()
{
    // Animal a;
    Dog d; // 1) Dog::Dog()
    Cat c;
}
