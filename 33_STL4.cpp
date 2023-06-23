// 33_STL4.cpp
#include <iostream>
#include <algorithm>
using namespace std;

// sort에 정책을 전달해서,
// 오름차순/내림차순의 정책을 변경할 수 있습니다.
#if 1
bool compare(int a, int b)
{
    return a < b;
}

// 정책으로 전달되었을 때, 함수 포인터와 다르게
// 인라인화가 가능합니다.
class Compare {
public:
    bool operator()(int a, int b) const { return a > b; }
};

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    // sort(begin(x), end(x), compare);
    //                     bool (*)(int, int)

    // Compare cmp;
    // sort(begin(x), end(x), cmp);
    //                     Compare

    // sort(begin(x), end(x), Compare());

    // C++11, Lambda Expression
    //  : 실행 가능한 코드 조각을 참조하는 기술
    // => 익명의 함수 객체를 생성하는 문법
    sort(begin(x), end(x), [](int a, int b) { return a < b; });

    for (auto e : x) {
        cout << e << endl;
    }
}
#endif

#if 0
inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    int result = add(10, 20);

    // 인라인 함수라도 함수 포인터에 담아서 호출하면,
    // 인라인 최적화가 불가능합니다.
    int (*fp)(int, int) = add;
    result = fp(10, 20);
}
#endif
