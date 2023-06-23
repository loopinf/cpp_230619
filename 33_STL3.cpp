// 33_STL3.cpp
#include <iostream>
using namespace std;

#include <algorithm>

//  int x[5]    ---> 반복자 ---->  <algorithm> 일반함수
//  vector<int>
//   list<int>

// C++에서 실패의 의미로 past the end를 사용합니다.
template <typename T1, typename T2>
T1 xfind(T1 begin, T1 end, T2 n)
{
    while (begin != end) {
        if (*begin == n) {
            break;
        }

        ++begin;
    }

    // return *begin == n ? begin : nullptr;
    return begin;
}

#include <vector>
#include <list>

int main()
{
    // int x[5] = { 1, 2, 3, 4, 5 };
    list<int> x = { 1, 2, 3, 4, 5 };

    // auto p = xfind(begin(x), end(x), 3);
    auto p = find(begin(x), end(x), 3);
    // xfind(int*, int*, int)

    if (p != end(x)) {
        cout << *p << endl;
    }
}

#if 0
int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };

    int* p = xfind(x, x + 5, 3);
    if (p != x + 5) {
        cout << *p << endl;
    }
}
#endif
