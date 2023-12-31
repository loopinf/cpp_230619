// 30_추상클래스2.cpp
#include <iostream>
using namespace std;

class Camera {
public:
    void StartRecording() { cout << "Start Recording" << endl; }
    void StopRecording() { cout << "Stop Recording" << endl; }
};

class HDCamera {
public:
    void StartRecording() { cout << "HDCamera> Start Recording" << endl; }
    void StopRecording() { cout << "HDCamera> Stop Recording" << endl; }
};

class Car {
    Camera* camera;

public:
    Car(Camera* p)
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

int main()
{
    Camera camera;
    Car car(&camera);

    car.Go();
}
