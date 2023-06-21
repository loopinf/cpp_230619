// 27_상속5.cpp
#include <iostream>
#include <string>
using namespace std;

// 생성자에서 초기화리스트를 반드시 정의해야 하는 경우
// 1) const 멤버
// 2) reference 멤버
// 3) 기본 생성자를 제공하지 않는 멤버 객체
// 4) 기본 생성자를 제공하지 않는 부모

class Animal {
    int age_;

public:
    // 부모의 멤버는 부모의 생성자를 통해 초기화되어야 합니다.
    Animal(int n)
        : age_(n)
    {
    }
};

// 자신의 멤버와 부모의 멤버를 초기화하는 책임이 있습니다.
class Dog : public Animal {
    int color_;
    string name_;

public:
    Dog(int age, int color, const string& name)
        : Animal(age)
        , color_(color)
        , name_(name)
    {
    }
};

int main()
{
}

#if 0
class Dog : public Animal {
public:
    Dog()
        : Animal(42)
    {
    }
};


int main()
{
    Dog d;
}
#endif
