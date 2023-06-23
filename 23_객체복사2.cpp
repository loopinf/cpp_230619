// 23_객체복사2.cpp
#include <iostream>
using namespace std;

// 복사 정책
// 1) 깊은 복사
// 2) 참조 계수
// 3) 복사 금지

class User {
    char* name;
    int age;

public:
    User(const User& rhs)
        : age(rhs.age)
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // a = a;
    User& operator=(const User& rhs)
    {
        // 1. 자신과 동일한 객체인지 확인합니다.
        if (&rhs == this) {
            return *this;
        }

        // 2. 자신이 소유한 자원을 파괴합니다.
        delete[] name;

        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);

        return *this;
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void Print() { cout << name << ", " << age << endl; }
};

int main()
{
    User user("Tom", 42);
    user.Print();

    User other = user;
    other.Print();
}
