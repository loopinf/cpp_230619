// 28_다형성4.cpp
#include <iostream>
using namespace std;

class Car {
public:
    virtual void Start() const { cout << "Car Start" << endl; }

    void foo();
};

// Car.cpp => 인라인 최적화 불가능
// Car.h   => 인라인 최적화
void Car::foo()
{
}

class Sedan : public Car {
public:
    // 부모가 제공하는 멤버 함수를 재정의할 수 있습니다.
    // => 함수 오버라이딩(Overriding)
    virtual void Start() const { cout << "Sedan Start" << endl; }
};

// 함수 바인딩(Binding)
//  - 어떤 함수가 호출될지 결정하는 것
//    p->Start()

// 1) 정적 바인딩(static binding)
//   : 컴파일 타임에 컴파일러가 결정합니다.
//     p의 타입이 Car 타입이기 때문에, Car의 함수가 호출됩니다.
//     => 인라인 최적화가 가능합니다.

// 2) 동적 바인딩(dynamic binding)
//   : 컴파일 타임에 실행 시간에 p가 참조하는 객체의 타입을 조사해서
//     함수를 호출하는 코드를 삽입합니다.
//     => 실행 시간에 결정됩니다.

// 멤버 함수의 호출을 동적 바인딩으로 바꾸는 키워드
// => virtual
//    : 실행 시간에 판단하겠다.
// => Linux / Unix
//      VFS(Virtual File System)
//          write() -------> 일반 파일 ---> 파일에 저장
//                        디바이스 파일 ---> 디바이스 제어
//                           소켓 파일 ---> 패킷 전송

int main()
{
    Car c;
    // c.Start();
    Sedan s;
    // s.Start();

    Car* p = &c;
    p->Start();

    p = &s;
    p->Start();
}
