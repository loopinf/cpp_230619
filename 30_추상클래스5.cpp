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
