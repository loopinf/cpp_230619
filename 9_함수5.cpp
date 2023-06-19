// 9_함수5.cpp
#include <iostream>
using namespace std;

// inline int square(int x) { return x * x; }
// inline double square(double x) { return x * x; }
// 위의 함수들은 함수의 인자와 반환 타입만 다르고, 구현(알고리즘)은 동일합니다.
// C++은 함수의 타입만 다르고 구현이 동일한 경우,
// 코드를 컴파일러가 자동으로 생성하는 문법이 있습니다.
// => C++ Template

template <typename TYPE>
inline TYPE square(TYPE x) { return x * x; }

int main()
{
    cout << square(10) << endl; // TYPE -> int
    cout << square(10.4) << endl; // TYPE -> double
}
