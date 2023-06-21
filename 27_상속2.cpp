// 27_상속2.cpp
#include <iostream>
using namespace std;

class Animal {
    int age;
};
// 1. 상속 하는 방법
//   - class 자식클래스 : [public] 부모클래스
//                  => 접근 변경자
//   > 객체지향 설계에서 말하는 상속은 C++에서는 public 상속만
//     포함됩니다.

// 2. Animal: 부모 클래스, Base      Super
//       Dog: 자식 클래스, Derived   Sub

class Dog : public Animal {
    int color;
};

int main()
{
    Animal a;
    Dog d;

    cout << sizeof(a) << endl;
    cout << sizeof(d) << endl;
}
