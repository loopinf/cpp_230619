// 27_상속.cpp
#include <iostream>
using namespace std;

// 상속: 객체 지향 언어의 핵심적인 문법 중 하나입니다.
#if 0
class Dog {
    //-----
    string name;
    int color;
    int age;
    //-----
    string owner;

public:
    //----
    string GetName() const { return name; }
    int GetColor() const { return color; }
    int GetAge() const { return age; }
    //----
    string GetOwner() const { return owner; }
};

class Cat {
    string name;
    int color;
    int age;
    int speed;

public:
    string GetName() const { return name; }
    int GetColor() const { return color; }
    int GetAge() const { return age; }
    int GetSpeed() const { return speed; }
};

int main()
{
    Dog d;
    Cat c;

    d.GetName();
    c.GetName();

    d.GetOwner();
    c.GetSpeed();
}
#endif

class Animal {
    //-----
    string name;
    int color;
    int age;
    //-----
public:
    //----
    string GetName() const { return name; }
    int GetColor() const { return color; }
    int GetAge() const { return age; }
    //----
};

class Dog : public Animal {
    string owner;

public:
    string GetOwner() const { return owner; }
};

class Cat : public Animal {
    int speed;

public:
    int GetSpeed() const { return speed; }
};

int main()
{
    Dog d;
    Cat c;

    d.GetName();
    c.GetName();

    d.GetOwner();
    c.GetSpeed();
}
