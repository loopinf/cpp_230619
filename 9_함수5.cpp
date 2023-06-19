// 9_함수5.cpp
#include <iostream>
using namespace std;

// inline int square(int x) { return x * x; }
// inline double square(double x) { return x * x; }
// 위의 함수들은 함수의 인자와 반환 타입만 다르고, 구현(알고리즘)은 동일합니다.
// C++은 함수의 타입만 다르고 구현이 동일한 경우,
// 코드를 컴파일러가 자동으로 생성하는 문법이 있습니다.
// => C++ Template

// 함수 템플릿
template <typename TYPE> // 타입 파라미터
inline TYPE square(TYPE x)
{
    return x * x;
}

// 1) 전달된 인자의 타입을 통해 TYPE을 결정하고, 컴파일 타임에 함수를 생성합니다.
// 2) 컴파일 타임에 코드를 생성하기 때문에,
//    템플릿 기반의 코드는 컴파일 시간이 증가될 수 있습니다.
// 3) 전달된 인자의 타입을 통해, 템플릿의 타입이 결정되고,
//    다양한 타입이 전달될 경우, 코드 메모리 사용량이 증가할 수 있습니다.
//   > 인라인 최적화를 통해 코드 메모리 사용량을 최적화할 수 있습니다.

int main()
{
    cout << square(10) << endl; // TYPE -> int
    cout << square(10.4) << endl; // TYPE -> double

    cout << square<double>(3.14F) << endl;
    // 명시적으로 타입을 지정할 수 있습니다.
}
