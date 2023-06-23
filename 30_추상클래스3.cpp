// 30_추상클래스3.cpp
#include <iostream>
using namespace std;

// 1. Car ----------> Camera
//  원인: Car 클래스가 Camera 클래스에 의존합니다.
//     "강한 결합"이 형성되어 있다.
//  => 새로운 카메라가 추가될때마다 자동차의 코드는 수정되어야 합니다.
//  => "OCP를 만족하지 않는다."

// 2. 해결방법
//  => 약한 결합 / 느슨한 결합
//    Car ------------> <<BlackBox>>
//                           |
//                    ---------------
//                    |             |
//                  Camera        HDCamera
//  => 새로운 기능이 추가되어도, 기존 코드는 수정되지 않습니다.
//    "OCP"를 만족합니다.
//  => DIP(Dependency Inversion Principle, 의존 관계 역전 원칙)
//     - 클래스는 구체적인 타입에 의존하는 것이 아니라, 추상 클래스나 인터페이스에
//       의존해야 한다.
//     * 교체 가능한 유연한 설계 *

// 1) 카메라의 제작자와 자동차의 제작자가 카메라의 인터페이스(사용 방법)를 약속합니다.

// C++에서 인터페이스를 정의하는 방법
// => 명시적인 인터페이스/프로토콜 약속
class BlackBox {
public:
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2) 자동차의 제작자는 카메라의 인터페이스를 이용하는 코드를 작성합니다.
class Car {
    BlackBox* camera;

public:
    Car(BlackBox* p)
        : camera(p)
    {
    }

    void Go()
    {
        camera->StartRecording();
        cout << "Car go" << endl;
        camera->StopRecording();
    }
};

// 3) 카메라의 제작자는 BlackBox의 인터페이스를 기반으로 카메라를 제작합니다.
//  "카메라는 BlackBox를 상속합니다." 라고 하지 않고
//  "카메라는 BlackBox의 인터페이스를 구현합니다." 라고 합니다.
//  class Camera extends BlackBox {}
//  class Camera implements BlackBox {}

class Camera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "Start Recording" << endl;
    }

    void StopRecording() override
    {
        cout << "Stop Recording" << endl;
    }
};

class HDCamera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "HDCamera Start Recording" << endl;
    }

    void StopRecording() override
    {
        cout << "HDCamera Stop Recording" << endl;
    }
};

int main()
{
    HDCamera camera;
    Car car(&camera); // 정책을 실행 시간에 결정합니다.

    car.Go();
}
