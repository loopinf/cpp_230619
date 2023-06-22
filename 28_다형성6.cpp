// 28_다형성6.cpp
#include <iostream>
using namespace std;

// C++11, final
// - final 멤버 함수 => 오버라이딩 금지
// - final 클래스   => 상속 금지

class Car {
public:
    virtual void Start() const
    {
        cout << "Car::Start" << endl;
    };
};

class Sedan : public Car {
public:
    // 모든 Sedan은 반드시 아래 함수를 수행해야 합니다.
    // => final 멤버 함수는 오버라이딩 금지됩니다.
    void Start() const override final
    {
        cout << "Sedan::Start" << endl;
    }
};

// 클래스에 final이 지정되면, 상속이 금지됩니다.
class Avante final : public Sedan {
public:
#if 0
    void Start() const override
    {
        cout << "Avante::Start" << endl;
    }
#endif
};

#if 0
class NewAvante : public Avante {
};
#endif

int main()
{
    Sedan* p = new Avante;
    p->Start();
}
