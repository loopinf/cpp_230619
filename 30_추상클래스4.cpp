// 30_추상클래스3.cpp
#include <iostream>
using namespace std;

// 템플릿을 기반으로 아래와 같이 작성하는 경우
// 암묵적인 인터페이스의 약속이 필요합니다.
// => BlackBox 타입은
//    StartRecording() 함수와
//    StopRecording() 함수를 제공하고 있다.

// => Policy Based Design, 단위 전략

template <typename BlackBox>
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

class Camera {
public:
    void StartRecording()
    {
        cout << "Start Recording" << endl;
    }

    void StopRecording()
    {
        cout << "Stop Recording" << endl;
    }
};

class HDCamera {
public:
    void StartRecording()
    {
        cout << "HDCamera Start Recording" << endl;
    }

    void StopRecording()
    {
        cout << "HDCamera Stop Recording" << endl;
    }
};

int main()
{
    HDCamera camera;
    Car car(&camera); // 정책을 컴파일 타임에 결정합니다.

    car.Go();
}
