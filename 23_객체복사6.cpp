// 23_객체복사.cpp
#include <iostream>
using namespace std;

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

    User(const User& rhs)
        : age(rhs.age)
    {
        cout << "복사 생성자" << endl;
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // Move Constructor(이동 생성자)
    // => 소유권 이동
    User(User&& rhs)
        : name(rhs.name)
        , age(rhs.age)
    {
        cout << "이동 생성자" << endl;
        rhs.name = nullptr;
    }

    ~User()
    {
        delete[] name;
    }

    void Print()
    {
        printf("%p\n", name);

        // cout << name << ", " << age << endl;
    }
};

#if 0
int main()
{
#if 0
    User user("Tom", 42);
    user.Print();

    User other = user;
    other.Print();
#endif
    // 소유권 이동
    // User other = User("Tom", 42);
    // other.Print();

    User user("Tom", 42);

    // User other = user; // 복사 생성자
    User other = std::move(user);

    user.Print();
    other.Print();
}
#endif

template <typename T>
void Swap(T& a, T& b)
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(a);
}

// 1. 복사 생성자를 제공하지 않으면,
//    컴파일러가 멤버를 복사하는 복사 생성자를 제공합니다.

// 2. 이동 생성자를 제공하지 않으면
//    컴파일러가 멤버를 이동하는 이동 생성자를 제공합니다.

// 3. 복사 생성자를 금지하면, 이동 생성자도 금지됩니다.

class AAA {
public:
    AAA() { }
    // AAA(const AAA& rhs) = delete;
};

int main()
{
    // AAA a;
    // AAA b = std::move(a);
    int a = 10;
    int b = std::move(a);

    cout << a << endl;
    cout << b << endl;
}
