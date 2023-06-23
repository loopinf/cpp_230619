// 28_다형성6.cpp
#include <iostream>
using namespace std;

// C++11, final
// - final 멤버 함수 => 오버라이딩 금지
// - final 클래스   => 상속 금지

#if 1
class Car {
public:
    virtual void Start() const = 0;
    // {
    //     cout << "Car::Start" << endl;
    // };
};

class Sedan : public Car {
public:
    // 모든 Sedan은 반드시 아래 함수를 수행해야 합니다.
    // => final 멤버 함수는 오버라이딩 금지됩니다.
    // => Design Pattern, Template Method Pattern
    void Start() const override final
    {
        cout << "Sedan::Start" << endl;
        Go();
    }

    virtual void Go() const { cout << "Sedan Go" << endl; }
};

// 클래스에 final이 지정되면, 상속이 금지됩니다.
class Avante final : public Sedan {
public:
    void Go() const override
    {
        cout << "Avante Go" << endl;
    }

#if 0
    void Start() const override
    {
        cout << "Avante::Start" << endl;
    }
#endif
};

#if 0
class NewAvante : public Avante {
};
#endif

int main()
{
    Sedan* p = new Avante;
    p->Start();
}
#endif

#if 0
// C++ 특징
class Base {
public:
    // 생성자에서 가상함수를 호출하면,
    // 동적바인딩하지 않습니다.
    Base()
    {
        Init();
    }

    void foo()
    {
        Init(); // 객체의 타입에 따라, 함수가 결정됩니다.
    }

    virtual void Init()
    {
        cout << "Base::Init" << endl;
    }
};

class Derived : public Base {
public:
    void Init() override
    {
        cout << "Derived::Init" << endl;
    }
};

int main()
{
    Derived d;
    d.foo();

    Base b;
    b.foo();
}
#endif
