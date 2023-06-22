// 30_추상클래스.cpp
#include <iostream>
using namespace std;

// 순수 가상 함수를 1개 이상 가지는 클래스는
// 추상 클래스(abstract class)가 됩니다.
// => 인스턴스화가 불가능합니다.
class Shape {
public:
    virtual ~Shape() { }

    // 부모 입장에서는 구현을 제공할 필요가 없고,
    // 자식 클래스는 반드시 Draw를 오버라이딩 해야 합니다.
    // => 순수 가상 함수(pure virtual function)
    virtual void Draw() const = 0;
};

// 부모가 제공하는 순수 가상 함수를 재정의하지 않으면
// 자식 클래스도 추상 클래스 입니다.
// => 인스턴스화가 불가능합니다.
class Rect : public Shape {
public:
    void Draw() const override { cout << "Draw Rect" << endl; }
};

int main()
{
    // Shape s;
    Rect rect;
}
