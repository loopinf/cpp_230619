// 34_STL2.cpp
#include <iostream>
using namespace std;

// 반복자(Iterator)
//  - 배열에서 포인터의 역활과 유사합니다.

// 1) C++은 구간을 표현할 때,
//    반개 구간을 사용합니다.
//    [begin, end)

#if 0
int main()
{
    //          p1            p2
    //           |             |
    int x[5] = { 1, 2, 3, 4, 5 };

    int* p1 = x;
    int* p2 = x + 5; // past the end

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif
#include <vector>
#include <list>

// 컨테이너
//  begin: 컨테이너의 첫번째 요소를 가르키는 반복자
//    end: 컨테이너의 마지막 다음 위치를 가르키는 반복자

#if 0
int main()
{
    //               p1            p2
    //                |             |
    list<int> x = { 1, 2, 3, 4, 5 };

    // int* p1 = x;
    // int* p2 = x + 5; // past the end

    // vector<int>::iterator p1 = x.begin();
    // vector<int>::iterator p2 = x.end();
    auto p1 = x.begin();
    auto p2 = x.end();

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

// begin / end 일반 함수
// => 배열도 반복자를 꺼낼 수 있습니다.

int main()
{
    //               p1            p2
    //                |             |
    // int x[5] = { 1, 2, 3, 4, 5 };
    list<int> x = { 1, 2, 3, 4, 5 };

    auto p1 = begin(x);
    auto p2 = end(x);

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
