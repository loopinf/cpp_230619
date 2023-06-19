// 9_함수4.cpp
#include <iostream>
using namespace std;

// 매크로 함수
// 1. 우선순위 문제
//  => 치환 영역을 괄호로 감싸주어야 합니다.
//     전체 영역도 괄호로 감싸주어야 합니다.

#define SQUARE(x) ((x) * (x))
#define DBL(x) ((x) + (x))

#if 0
int main()
{
    int n = 10;
    cout << SQUARE(n + n) << endl;

    cout << DBL(n + n) * DBL(n + n) << endl;
    // cout << (n + n) + (n + n) * (n + n) + (n + n) << endl;
}
#endif

// 2. 매크로 함수는 ++x, --x, x++, x-- 같은 연산과 사용하였을 경우,
//    하나의 표현식에 두번 이상 치환된다면, 미정의 동작이 발생합니다.
#if 0
int main()
{
    int n = 0;

    ++n; // !!!
    cout << SQUARE(n) << endl;

    // cout << SQUARE(++n) << endl;
    //      ++n * ++n
}
#endif

// 인라인 함수
// 1. 함수를 호출하지 않고, 함수의 기계어로 호출 영역을 치환합니다.
//   매크로 함수: 전처리기에 의한 텍스트 치환
//   인라인 함수: 컴파일러에 의한 기계어 치환

// 2. 매크로 함수의 용도를 함수 호출 최적화로 사용하고 있다면,
//    인라인 함수를 사용하는 것이 권장됩니다.

// 3. 인라인 함수 특징
//  1) 컴파일 최적화 명령입니다.
//     인라인 여부를 컴파일러가 판단합니다.
//     /Ob1
//  2) 복잡한 함수가 인라인 최적화 될 경우,
//     함수의 기계어 치환으로 인해, 전체 코드 메모리 사용량이 증가할 수
//     있습니다.
//  3) 간결한 함수를 대상으로 인라인 최적화가 유용합니다.

// C99: static inline void foo() {}
// C++: inline void foo() {}
// => 인라인 함수는 internal linkage를 가지며,
//    반드시 헤더 파일에 두어야 합니다.

inline int square(int x)
{
    return x * x;
}

int main()
{
    int x = 10;
    cout << square(++x) << endl;
}
