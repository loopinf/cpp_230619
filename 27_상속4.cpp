// 27_상속4.cpp
#include <iostream>
using namespace std;

#if 0
class Base {
public:
    Base() { cout << "Base()" << endl; }
    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived()" << endl; }

    // Derived() : Base()  2) 부모의 기본 생성자 호출 - Base()
    // {}                  3) 자식의 생성자 블록 수행 - Derived()

    ~Derived()
    {
        cout << "~Derived()" << endl; // 2> 자식 클래스 소멸자 블록 수행

        // 3> 부모의 소멸자 호출 - Base::~Base()
    }
};

int main()
{
    Derived d; // 1) Derived::Derived()
} // 1> Derived::~Derived()
#endif

#if 1
class MB {
public:
    MB() { cout << "MB()" << endl; }
    ~MB() { cout << "~MB()" << endl; }
};

class MD {
public:
    MD() { cout << "MD()" << endl; }
    ~MD() { cout << "~MD()" << endl; }
};

class Base {
    MB mb;

public:
#if 0
    Base()
        : mb() // 3) 부모의 멤버 기본 생성자 호출 - MB()
    {
        cout << "Base()" << endl;
    }
#endif
    Base()
    {
        cout << "Base()" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base {
    MD md;

public:
#if 0
    Derived()
        : Base() // 2) Base() 생성자 호출
        , md() // 4) md() 생성자 호출
    {
        cout << "Derived()" << endl; // 5) 생성자 블록 수행
    }
#endif
    Derived()
    {
        cout << "Derived()" << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;

        // 1) 자식의 소멸자 호출
        // 2) 자식의 소멸자 수행
        // 3) 자식 멤버의 소멸자 호출
        // 4) 부모의 소멸자 호출
        // 5) 부모의 소멸자 수행
        // 6) 부모의 멤버의 소멸자 호출
    }
};

int main()
{
    Derived d; // 1) Derived::Derived()
}
#endif
