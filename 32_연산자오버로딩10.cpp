// 32_연산자오버로딩10.cpp
#include <iostream>
using namespace std;

bool isDivide(int n) { return n % 3 == 0; }

// 함수는 동작은 있지만 상태는 없습니다.
// 함수 객체는 클래스 이므로 상태가 있습니다.
class IsDivide {
    int value;

public:
    IsDivide(int n)
        : value(n)
    {
    }

    bool operator()(int n) const { return n % value == 0; }
};

int main()
{
    IsDivide d(4);

    cout << d(9) << endl;
}
