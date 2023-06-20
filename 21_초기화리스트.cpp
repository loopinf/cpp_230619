// 21_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이점을 이해해야 합니다.

// 2. C++ 에서 반드시 초기화가 필요한 것
//   1) const
//   2) reference

// 3. 생성자에서 멤버 데이터를 초기화하기 위해서는
//    초기화 리스트의 문법을 이용해야 합니다.

class Sample {
    const int x;
    int& y;

public:
    Sample(int a, int& r)
        : x(a)
        , y(r)
    {
    }

#if 0
    Sample(int a, int& r)
    {
        x = a; // 초기화가 아닌 대입입니다.
        y = r;
    }
#endif
};

int main()
{
}

#if 0
int main()
{
    int a = 3; // 초기화
    a = 3; // 대입

    const int c = 100;

    int& r = a;
}
#endif
