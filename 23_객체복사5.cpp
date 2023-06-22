// 23_객체복사5.cpp
#include <iostream>
using namespace std;

// 복사 정책

// 3) 복사 금지
//   => 복사를 금지하면, 이동도 금지가 됩니다.
//   => 소유권 이동은 같이 구현하는 경우가 많습니다.

class User {
    char* name;
    int age;

    // 복사 금지 하는 방법
    // 1) private 영역에 선언만 합니다.
    // User(const User&);

    // 2) delete function => 복사 금지
    User(const User&) = delete;
    // User(User&&) = delete;

public:
    User(User&& rhs)
        : name(rhs.name)
        , age(rhs.age)
    {
        rhs.name = nullptr;
        rhs.age = 0;
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

    void Print()
    {
        if (!name) {
            printf("%p\n", name);
            return;
        }

        cout << name << ", " << age << endl;
    }
};

// 복사 금지 + 소유권 이동
// => std::unique_ptr

int main()
{
    User user("Tom", 42);
    user.Print();

    User other = std::move(user);
    user.Print();
    other.Print();
}
