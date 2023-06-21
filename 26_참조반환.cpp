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

#if 0
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

    // Builder Pattern
    // Chaining
    user.SetName("Tom")
        .SetAge(42)
        .SetAddress("Seoul")
        .SetJob("Student");
}
#endif

// Telescoping Constructor Pattern => Java Idioms
// => 생성자의 인자가 많을 경우, 빌더를 고려해라

#if 0
class User {
    string name_; // 필수
    int age_; // 옵션
    string address_; // 옵션
    string job_; // 옵션
public:
    User(const string& name)
        : name_(name)
    {
    }

    User(const string& name, int age)
        : name_(name)
        , age_(age)
    {
    }

    User(const string& name, int age, const string& address)
        : name_(name)
        , age_(age)
        , address_(address)
    {
    }

    User(const string& name, int age, const string& address, const string& job)
        : name_(name)
        , age_(age)
        , address_(address)
        , job_(job)
    {
    }
};

int main()
{
    User user1("Tom");
    User user2("Tom", 42);
    User user3("Tom", 42, "Seoul");
    User user4("Tom", 42, "Student", "Seoul");
}
#endif

// 안돼니 해결해야 한다.
class User {
    string name_; // 필수
    int age_; // 옵션
    string address_; // 옵션
    string job_; // 옵션

    User(const string& name, int age, const string& address, const string& job)
        : name_(name)
        , age_(age)
        , address_(address)
        , job_(job)
    {
    }

    User(const UserBuilder& builder)
        : name_(builder.name_)
        , age_(builder.age_)
        , address_(builder.address_)
        , job_(builder.job_)
    {
    }

    friend class UserBuilder;
};

class UserBuilder {
    string name_; // 필수
    int age_; // 옵션
    string address_; // 옵션
    string job_; // 옵션
public:
    UserBuilder(const string& name)
        : name_(name)
    {
    }

    UserBuilder& SetAge(int age)
    {
        age_ = age;
        return *this;
    }

    UserBuilder& SetAddress(const string& address)
    {
        address_ = address;
        return *this;
    }

    UserBuilder& SetJob(const string& job)
    {
        job_ = job;
        return *this;
    }

    User Build()
    {
        return User(*this);
    }

    friend class User;
};

int main()
{
    User user = UserBuilder("Tom")
                    .SetAge(42)
                    .SetAddress("Seoul")
                    .SetJob("Student")
                    .Build();
}

#if 0
int main()
{
    User user1("Tom");
    User user2("Tom", 42);
    User user3("Tom", 42, "Seoul");
    User user4("Tom", 42, "Student", "Seoul");
}
#endif
