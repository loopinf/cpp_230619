// 30_추상클래스5.cpp
#include <iostream>
using namespace std;

// 인터페이스는 교체 가능한 유연한 설계를 만들지만
// 인터페이스에 새로운 기능을 추가하기 어렵다.
// => ISP(Interface Segregation Principle, 인터페이스 분리 원칙)
// : 범용 인터페이스보다 세분화된 인터페이스가 좋다.

class MP3 {
public:
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // ----
    virtual void PlayOneMinute()
    {
        // 인터페이스에 기본 구현을 제공하자. => defender method
        Play();
        //...
        Stop();
    }
    // ----
};

class Car {
    MP3* mp3;

public:
    Car(MP3* p)
        : mp3(p)
    {
    }

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();

        mp3->PlayOneMinute();
    }
};

class Player : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};

int main()
{
}

// SOLID - 객체 지향 5대 원칙
// 1) SRP - 단일 책임이 원칙
//     > 모든 클래스는 단 하나의 책임을 가져야 한다.
// 2) OCP
//     > 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
//       새로운 기능이 추가되어도 기존 코드는 수정되면 안된다.
// 3) LSP
//     > 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
//       자식의 공통의 기능은 부모로부터 비롯되어야 한다.
//       "상속" => 다형성
// 4) ISP
//    > 범용 인터페이스보다 세분화된 인터페이스가 좋다.
// 5) DIP
//    > 클래스는 구체적인 타입에 의존하는 것이 아니라,
//      추상 클래스나 인터페이스에 의존해야 한다.
