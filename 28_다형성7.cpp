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
    int n = 100;

public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal {
    int n = 42;

public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }

    void Print() const
    {
        cout << Animal::n << endl; // 부모의 멤버
        cout << n << endl; // 자식의 멤버
    }
};

int main()
{
    Dog d;
    d.Print();

    Animal* p = new Dog;
    // 부모의 포인터/참조를 통해 자식의 기능을 이용하기 위해서는
    // 반드시 해당 기능이 부모로부터 비롯되어야 합니다.
    cout << "xxxx:" << p->n << endl;

    delete p; // => 정적 바인딩 - Animal::~Animal()
              // => 동적 바인딩 - Dog::~Dog()
}
