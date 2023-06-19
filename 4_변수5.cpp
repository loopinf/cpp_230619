// 4_변수5.cpp
#include <iostream>
using namespace std;

// decltype은 동일한 타입을 구할 수 있습니다.
// auto와 달리 우항이 필요하지 않습니다.
// => GNU extension의 확장 문법인 typeof와 동일합니다.

int main()
{
    const int c = 42;
    auto n = c;

    // c와 동일한 타입의 변수를 만들고 싶습니다.
    // : C++11, decltype
    decltype(c) c2 = 100;
    // c2 = 1000;

    int n2 = 100;
    decltype(n2) n3;
}
