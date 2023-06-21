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
//   1) 클래스
//     Sample::cnt / Sample::hoo()
//   2) 객체
//     c.cnt / c.hoo()

// 4. 멤버 데이터 / 멤버 함수
//  > 객체를 통해서만 접근이 가능합니다.

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

int main()
{
    cout << Sample::cnt << endl;

    Sample s;
    Sample::joo(&s);

    cout << s.data << endl;

    s.foo();
    s.goo();
}
