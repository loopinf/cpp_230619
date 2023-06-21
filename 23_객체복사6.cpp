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

int main()
{
}
