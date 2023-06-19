// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = 10;
    int x1[3] = { 10, 20, 30 };
    Point pt1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2(10);
    int x2[3] { 10, 20, 30 };
    Point pt2 { 10, 20 };

    // Uniform Initialization(C++11, 일관된 초기화)
    // - Copy Initialization
    int n3 = { 10 };
    int x3[3] = { 10, 20, 30 };
    Point pt3 = { 10, 20 };

    // - Direct Initialization
    int n4 { 10 };
    int x4[3] { 10, 20, 30 };
    Point pt4 { 10, 20 };
}
