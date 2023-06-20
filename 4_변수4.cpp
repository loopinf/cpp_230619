// 4_변수4.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    int* p1 = x; // 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다. => Decay

    int(*p2)[3] = &x; // Decay 예외: 1. sizeof, 2. &
}
#endif

// auto, C++11
// 1. 우항의 표현식을 통해 컴파일 타임에 타입을 추론합니다.
// 2. 의존성이 있는 타입의 변화에 대응하기 쉬워집니다.
//   Type Deduction

// 주의사항
// - 반드시 우항이 필요합니다.
//   반드시 초기화가 필요합니다.
// - 우항과 동일한 타입이 아닌 추론입니다.
// - C의 auto 키워드를 다른 의미로 사용하고 있습니다.

#if 0
int main()
{
    // auto int n;

    int x[3] = { 10, 20, 30 };

    auto p1 = x; // p1 -> int*
    auto p2 = &x; // p2 -> int(*)[3]

    // auto x; - 컴파일 오류!
}
#endif

#if 1
int main()
{
    const int c = 42;
    // c = 100;

    // 1) const 제한자는 사라집니다.
    const auto c2 = c;
    // c2 = 42;

    int n = 42;
    int& r = n;

    // 2) & 도 사라집니다.
    auto& r2 = r;
    r2 = 100;
    cout << n << endl;
}
#endif

#if 0
void foo()
{
    cout << "foo" << endl;
}

int main()
{
    // auto f = foo;
    // f는 void (*)();

    // void (*f)() = foo;
    auto f = foo;
    f();
}
#endif
