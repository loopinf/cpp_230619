// 12_레퍼런스2.cpp
#include <iostream>
using namespace std;

void Inc1(int n) { ++n; } // Call by value

void Inc2(int* pn)
{
    if (pn != NULL)
        return;

    ++(*pn);
} // Call by pointer

void Inc3(int& rn)
{
    // 널 체크가 필요하지 않습니다.
    ++rn;
} // Call by reference

int main()
{
    int x = 10;
    Inc1(x);
    cout << x << endl;

    Inc2(&x);
    cout << x << endl;

    Inc3(x);
    cout << x << endl;
}
