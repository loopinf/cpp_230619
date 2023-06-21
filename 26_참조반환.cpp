// 26_참조반환.cpp
#include <iostream>
using namespace std;

#if 0
class User {
    string name;
    int age;
    string address;
    string job;

public:
    // Setter
    void SetName(const string& n) { name = n; }
    void SetAge(int n) { age = n; }
    void SetAddress(const string& a) { address = a; }
    void SetJob(const string& j) { job = j; }
};

int main()
{
    User user;
    user.SetName("Tom");
    user.SetAge(42);
    user.SetAddress("Seoul");
    user.SetJob("Student");
}
#endif

#if 0
class User {
    string name;
    int age;
    string address;
    string job;

public:
    // Setter
    User* SetName(const string& n)
    {
        name = n;
        return this;
    }

    User* SetAge(int n)
    {
        age = n;
        return this;
    }

    User* SetAddress(const string& a)
    {
        address = a;
        return this;
    }

    User* SetJob(const string& j)
    {
        job = j;
        return this;
    }
};

int main()
{
    User user;
    user.SetName("Tom");
    user.SetAge(42);
    user.SetAddress("Seoul");
    user.SetJob("Student");

    // Chaining
    user.SetName("Tom")
        ->SetAge(42)
        ->SetAddress("Seoul")
        ->SetJob("Student");
}
#endif

class User {
    string name;
    int age;
    string address;
    string job;

public:
    // Setter
    User& SetName(const string& n)
    {
        name = n;
        return *this;
    }

    User& SetAge(int n)
    {
        age = n;
        return *this;
    }

    User& SetAddress(const string& a)
    {
        address = a;
        return *this;
    }

    User& SetJob(const string& j)
    {
        job = j;
        return *this;
    }
};

int main()
{
    User user;
    user.SetName("Tom");
    user.SetAge(42);
    user.SetAddress("Seoul");
    user.SetJob("Student");

    // Chaining
    user.SetName("Tom")
        .SetAge(42)
        .SetAddress("Seoul")
        .SetJob("Student");
}
