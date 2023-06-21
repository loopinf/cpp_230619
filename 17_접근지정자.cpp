// 17_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. struct의 기본 접근 지정자는 public 입니다.
//     class의 기본 접근 지정자는 private 입니다.

// 2. private은 외부에서 접근이 불가능합니다.
//    멤버 함수를 통해서 접근이 가능합니다.
//    - friend 함수 / friend 클래스

// 3. friend
//   : friend로 선언된 함수와 클래스는 private 멤버에 접근이 가능합니다.
//  > 캡슐화의 정책을 깨뜨리지 않고, 캡슐화의 경계를 확장할 수 있습니다.
// https://google.github.io/styleguide/cppguide.html

class User {
private:
    string name;
    int age;

public:
    // string GetName() { return name; }
    // int GetAge() { return age; }

    User(string s, int n)
    {
        name = s;
        age = n;
    }

    // friend 선언
    friend void PrintUser(User user);
    friend class UserPrinter;
};

class UserPrinter {
public:
    void PrintUser(User user)
    {
        cout << user.name << ", " << user.age << endl;
    }
};

// 일반 함수
void PrintUser(User user)
{
    cout << user.name << ", " << user.age << endl;
}

int main()
{
    // User user("Tom", 42);
    User user { "Tom", 42 };
    PrintUser(user);

    UserPrinter printer;
    printer.PrintUser(user);

    // cout << user.name << endl;
}
