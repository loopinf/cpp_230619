// 33_STL5.cpp
#include <iostream>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator()(int a, int b) const { return a > b; }
};

class IsDivide {
    int value;

public:
    IsDivide(int n)
        : value(n)
    {
    }

    bool operator()(int n) const { return n % value == 0; }
};

// Lambda & Closure(람다와 클로저)
// 람다: 실행 가능한 코드 조각을 참조하는 기술
// 클로저: 외부의 변수를 캡쳐합니다.

#if 0
int main()
{
    // [](int a, int b) { return a > b; }
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    IsDivide div(3);

    auto p = find_if(begin(v), end(v), div);
    if (p != end(v)) {
        cout << *p << endl;
    }

    int value = 3;
    auto p2 = find_if(begin(v), end(v),
        [value](int n) { return n % value == 0; });

    if (p2 != end(v)) {
        cout << *p2 << endl;
    }
}
#endif

template <typename T>
void foo(T fn)
{
    fn();
    fn();
    fn();
}

int main()
{
    int value = 0;
    int n = 100;

    // [value]: Capture by value => 수정이 불가능합니다.
    // [&value]: Capture by reference
    foo([&value, n]() {
        ++value;
        cout << "fn: " << value << endl;
        cout << "n: " << n << endl;
    });
    cout << value << endl;

    auto fn = [&value, n]() {
        ++value;
        cout << "fn: " << value << endl;
        cout << "n: " << n << endl;
    };

    foo(fn);
    foo(fn);

    auto f = [](int a, int b) -> int { return a + b; };
    // 람다 표현식의 반환 타입은 -> 를 통해 명시할 수 있습니다.
    cout << f(100, 200) << endl;
}
