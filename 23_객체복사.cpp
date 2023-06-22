// 23_객체복사.cpp
#include <iostream>
using namespace std;

// 1) 컴파일러가 제공하는 복사 생성자는 멤버를 복사합니다.
// 2) 멤버 중에 포인터 멤버가 존재하는 경우,
//    얕은 복사(Shallow Copy) 문제가 발생합니다.
// 3) 반드시 멤버 중에 포인터 멤버가 존재하면,
//    복사 생성자를 제공해서, 문제를 해결해야 합니다.

// 복사 정책
// 1) 깊은 복사
// 2) 참조 계수
// 3) 복사 금지

// 핵심:
// => 클래스가 포인터 멤버를 가지는 경우
//   : 얕은 복사 문제가 발생합니다.
//   반드시 복사 / 이동의 생성자와 연산자를 제공해서,
//   깊은 복사 / 참조 계수 / 복사 금지 / 소유권 이동의 개념을
//   제공해야 합니다.

class User {
    char* name;
    int age;

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

    User other = std::move(user);
    other.Print();
}
