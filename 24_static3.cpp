// 24_static3.cpp
#include <iostream>
using namespace std;

// 1. 정적 멤버 데이터
// > 전역 변수와 수명이 동일합니다.
//   클래스의 접근 제어를 사용할 수 있습니다.

// 2. 정적 멤버 함수
// > 전역 함수와 동일합니다.
//   클래스의 접근 제어를 사용할 수 있습니다.

// 3. 정적 멤버 데이터 / 정적 멤버 함수
//  > 객체를 생성하지 않아도, 사용할 수 있습니다.
//   1) 클래스
//     Sample::cnt / Sample::hoo()
//   2) 객체
//     c.cnt / c.hoo()

// 4. 멤버 데이터 / 멤버 함수
//  > 객체를 통해서만 접근이 가능합니다.

#if 1
class Sample {
public:
    // static constexpr int cnt = 100;
    static int cnt;
    int data;

public:
    // 멤버 함수는 this가 전달됩니다.
    // void foo(Sample* this)
    void foo()
    {
        cout << cnt << endl; // 정적 멤버 데이터
        cout << data << endl; // 멤버 데이터

        hoo(); // 정적 멤버 함수 호출 가능
        goo(); // 멤버 호출 가능
    }

    void goo()
    {
    }

    // 정적 멤버 함수는 this가 전달되지 않습니다.
    static void hoo()
    {
        cout << cnt << endl; // 정적 멤버 데이터
        // cout << data << endl; // 멤버 데이터에 접근이 불가능합니다.
        //   this->data

        koo(); // 정적 멤버 함수 호출이 가능합니다.
        // goo();
        // this->goo(); - 멤버 함수를 호출할 수 없습니다.
    }

    static void koo()
    {
        cout << "koo" << endl;
    }

    // 명시적으로 객체의 주소를 전달받으면, 멤버 함수와 멤버 데이터에 접근이
    // 가능합니다.
    static void joo(Sample* self)
    {
        cout << self->data << endl;
        self->foo();
    }
};

int Sample::cnt = 0;

void handler()
{
    cout << "handler" << endl;
}

void foo(void (*f)())
{
    cout << "f start" << endl;
    f();
    cout << "f end" << endl;
}

int main()
{
    foo(handler);
    foo(Sample::koo);

    cout << Sample::cnt << endl;

    Sample s;
    Sample::joo(&s);

    cout << s.data << endl;

    s.foo();
    s.goo();
}
#endif

// Design Pattern
//  1995년 에릭감마 외 3명, Gang of Four, GoF
//   - 23가지 패턴

// 활용 1)
// Singleton Pattern
// - 의도: 오직 하나의 객체를 생성하고, 언제 어디서든 동일한 방법을 통해
//        객체를 참조할 수 있다.

#if 0
// 마이어스의 싱글톤
class Mouse {
    // 1) private 생성자
    Mouse() { }

public:
    // 2) 복사 금지
    Mouse(const Mouse& rhs) = delete;

    // 3) 언제 어디서든 객체를 참조할 수 있는 정적 멤버 함수
    static Mouse& GetInstance()
    {
        static Mouse m;
        return m;
    }
};

int main()
{
    Mouse& m1 = Mouse::GetInstance();
    Mouse& m2 = Mouse::GetInstance();

    cout << &m1 << endl;
    cout << &m2 << endl;
}
#endif

#if 1
// 2) 정적 팩토리 메소드
//  Factory: SW에서 객체를 생성하는 역활

#include <string>

class User {
    string id;

private:
    User(const string& i)
        : id(i)
    {
    }

public:
    static User* CreateWithEmail(const std::string& email)
    {
        return new User("email: " + email);
    }

    static User* CreateWithName(const std::string& name)
    {
        return new User("name: " + name);
    }

    void Print() { cout << id << endl; }

public:
#if 0
    User(const string& name) { }
    User(const string& email) { }
#endif
};

// 1. 생성자의 오버로딩을 통해 객체를 생성하는 다양한 방법을 제공할 수 있지만
//  오버로딩은 인자 타입이 다를 경우에만 가능합니다.

// 2. 생성자의 이름은 동일하기 때문에
//    객체 생성의 의도를 읽기 어렵다.

int main()
{
    // User user1("hello@gmail.com");
    // User user2("Tom");

    User* p1 = User::CreateWithEmail("hello@gmail.com");
    p1->Print();

    User* p2 = User::CreateWithName("Tom");
    p2->Print();
}
#endif
