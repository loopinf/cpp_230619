// 27_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모의 private은 자식 클래스에서 접근할 수 없다.

// 2. protected
//  : 외부에서 접근할 수 없지만, 자식 클래스는 접근이 가능합니다.

// 3. 접근 지정자
//  private: 외부 접근 불가능. friend 클래스 / 함수 접근 가능
//  protected: 외부 접근 불가능. 자식 클래스 접근 가능
//  public: 외부 접근 가능

// 4. 상속
//  => 부모 클래스와 자식 클래스가 강한 결합이 형성됩니다.
//  => 부모의 멤버를 자식이 직접 접근하기 보다는
//     부모가 제공하는 멤버 함수를 통해 이용해야 합니다.
//     "무분별한 상속은 위험합니다."

class Animal {
    int age = 100;

protected:
    // int age = 100;
    int GetAge() const { return age; }
};

class Dog : public Animal {
public:
    void PrintAge() const
    {
        // cout << age << endl;
        cout << GetAge() << endl;
    }
};

int main()
{
    Dog d;
    d.PrintAge();
}
