// 28_다형성.cpp
#include <iostream>
using namespace std;

class Animal { };
class Dog : public Animal { };
// 자식 클래스 is-a 부모 클래스
//   - Dog is an Animal

int main()
{
    Animal a;
    Dog d;

    Animal* pa = &a;
    Dog* pd = &d;

    Animal* pa2 = &d;
    Animal& r = d;
    // 부모의 포인터/참조 타입을 통해 자식의 객체를
    // 참조할 수 있습니다.
    //  : Upcasting
    // => 자식 타입의 주소 또는 참조는 부모 타입의 주소 또는 참조로의 암묵적인 변환이 허용됩니다.

    //-------
    // Dog* pd2 = &a;
    // : Downcasting
    //  자식 타입의 주소 또는 참조를 통해 부모 객체를 참조할 수 없습니다.
}
