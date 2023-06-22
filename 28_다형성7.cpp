// 28_다형성7.cpp
#include <iostream>
using namespace std;

// 1. 가상 소멸자가 필요한 이유를 정확하게 이해해야 합니다.
// 2. 부모의 소멸자가 가상이면, 자식의 소멸자도 가상입니다.

// 핵심: 부모 클래스는 반드시 소멸자를 가상으로 만들어야 합니다.
//      가상 소멸자가 없는 부모는 상속하면 안됩니다.

// 3. 자식의 소멸자에 override를 통해 부모의 소멸자가 가상인지
//    컴파일 타임 확인할 수 있습니다.

class Animal {
public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal {
public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }
};

int main()
{
    // Dog d;

    Animal* p = new Dog;

    delete p; // Animal::~Animal()
}
