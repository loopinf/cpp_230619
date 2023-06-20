// 19_소멸자.cpp
#include <iostream>
using namespace std;

#include <cstring>

// 1. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러가 아무일도 하지 않는 소멸자를 제공합니다.

// 2. 객체 내부에서 자원(메모리, 파일, 스레드, 락)을 할당하고 있다면,
//    반드시 소멸자를 통해 객체가 파괴되는 시점에 자원을 해지해야 합니다.

class Person {
    char* name;

public:
    Person(const char* s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    // 오직 1개만 제공할 수 있고, 인자는 없고, 반환타입도 없습니다.
    // 오버로딩도 불가능합니다.
    ~Person()
    {
        delete[] name;
    }

    void Print() { cout << name << endl; }
};

int main()
{
    Person person("Bob");
    person.Print();
}
