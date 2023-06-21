// 23_객체복사3.cpp
#include <iostream>
using namespace std;

#include <atomic>

// 복사 정책
// 2) 참조 계수

class User {
    char* name;
    int age;

    int* ref;

public:
    User(const User& rhs)
        : name(rhs.name)
        , age(rhs.age)
        , ref(rhs.ref)
    {
        ++(*ref);
        // 참조 계수 증감이 스레드 안전해야 합니다.
        // => Atomic operations(원자적 연산)
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int(1);
    }

    ~User()
    {
        if (--*ref == 0) {
            delete[] name;
            delete ref;
        }
    }

    void Print() { cout << name << ", " << age << endl; }
};

int main()
{
    atomic<int> ref(0);
    cout << ++ref << endl;

    User user("Tom", 42);
    user.Print();

    User other = user;
    other.Print();
}
