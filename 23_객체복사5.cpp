// 23_객체복사5.cpp
#include <iostream>
using namespace std;

// 복사 정책

// 3) 복사 금지
class User {
    char* name;
    int age;

    // 복사 금지 하는 방법
    // 1) private 영역에 선언만 합니다.
    // User(const User&);
    // 2) delete function => 복사 금지
    User(const User&) = delete;

public:
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

    // User other = user;
    // other.Print();
}
