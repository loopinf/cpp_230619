// 32_연산자오버로딩9.cpp
#include <iostream>
using namespace std;

// 함수 객체(Function Object, Functor)
//  - 정의: () 연산자를 재정의해서, 객체를 함수처럼 사용할 수 있습니다.
//  "Callable Object"

class Plus {
public:
    int operator()(int a, int b) const { return a + b; }
};

int main()
{
    Plus plus;

    int result = plus(10, 20);
    // plus.operator()(10, 20);

    cout << result << endl;
}
