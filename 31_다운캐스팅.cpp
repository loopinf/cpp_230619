// 31_다운캐스팅.cpp
#include <iostream>
using namespace std;

class Animal {
    int age;

public:
    // 부모의 소멸자는 반드시 가상이어야 합니다.
    virtual ~Animal() { }

    Animal(int n)
        : age(n)
    {
    }

    int GetAge() const { return age; }
};

class Dog : public Animal {
    int color;

public:
    Dog(int a, int c)
        : Animal(a)
        , color(c)
    {
    }

    int GetColor() const { return color; }
};

int main()
{
    Animal a(42);
    Dog d(100, 42);

    Animal* p = &a;
    p = &d;

    // p가 담고 있는 객체의 타입이 Dog 라면
    // GetColor를 출력하고 싶습니다.

    // 1. 부모의 포인터/참조 타입을 자식의 포인터/참조 타입으로의
    //    암묵적인 변환을 허용하지 않습니다.
    //    => 명시적인 캐스팅, 다운 캐스팅

    // 2. static_cast를 통해서 다운 캐스팅을 수행할 경우,
    //    잘못된 객체 타입에 대해서 감지할 수 없습니다.
    //   => 미정의 동작의 위험성이 있습니다.
    // Dog* pDog = static_cast<Dog*>(p);
    // cout << pDog->GetColor() << endl;

    // p가 Dog 타입인지 실행 시간에 조사해서
    //   => RTTI(Run Time Type Information)
    //    typeid 연산자
    //    1) 클래스  => type_info 구조체
    //    2) 객체   => type_info 구조체
    // - type_info는 가상 함수 테이블에 저장되어 있습니다.
    //   가상 함수 테이블이 없는 컴파일러가 타입을 보고 꺼냅니다.

#if 0
    if (typeid(Dog) == typeid(*p)) {
        Dog* pDog = static_cast<Dog*>(p);
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog 타입이 아닙니다." << endl;
    }
#endif

    // 3. dynamic_cast
    //  - 다운 캐스팅
    //  - 실행시간에 타입을 조사해서, 잘못된 타입인 경우
    //    nullptr을 반환합니다.

    Dog* pDog = dynamic_cast<Dog*>(p);
    // > 가상 함수 테이블이 존재하지 않는 경우,
    //   컴파일 오류가 발생합니다.

    if (pDog) {
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog 타입이 아닙니다." << endl;
    }
}
