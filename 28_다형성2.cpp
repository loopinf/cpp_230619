// 28_다형성2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog {
    int age;

public:
    Dog()
        : age(10)
    {
    }

    int GetAge() const { return age; }
};

class Cat {
    int age;

public:
    Cat()
        : age(100)
    {
    }

    int GetAge() const { return age; }
};

void PrintAge(const Dog& dog)
{
    cout << dog.GetAge() << endl;
}

void PrintAge(const Cat& cat)
{
    cout << cat.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
#endif

class Animal {
    int age;

public:
    Animal(int n)
        : age(n)
    {
    }

    int GetAge() const { return age; }
};

class Dog : public Animal {
public:
    Dog()
        : Animal(10)
    {
    }
};

class Cat : public Animal {
public:
    Cat()
        : Animal(10)
    {
    }
};

// Animal의 모든 자식 객체가 이용할 수 있는 함수입니다.
// => 동종을 처리하는 함수를 정의할 수 있습니다.
void PrintAge(const Animal& a)
{
    cout << a.GetAge() << endl;
}

int main()
{
    Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}
