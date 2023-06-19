// 12_레퍼런스3.cpp
#include <iostream>
#include <string>
using namespace std;

struct User {
    string name;
    int age;

    char address[1024];
};

// 사용자 정의 타입을 인자를 값으로 전달하면,
// 복사의 비용이 발생합니다.
void PrintUser1(User user)
{
    cout << user.name << ", " << user.age << endl;
}

// C: const User*
void PrintUser2(const User* user)
{
    if (user == NULL)
        return;

    cout << (*user).name << ", " << (*user).age << endl;
    cout << user->name << ", " << user->age << endl;
}

// C++: const User&
void PrintUser3(const User& user)
{
    cout << user.name << ", " << user.age << endl;
}

int main()
{
    cout << sizeof(User) << endl;

    User user = { "Tom", 42 };
    PrintUser1(user);

    PrintUser2(&user);
    PrintUser3(user);
}
