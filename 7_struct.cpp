// 7_struct.cpp
#include <iostream>
using namespace std;

// C++11: 멤버 초기화
struct Point {
    int x = 0;
    int y = 0;
    int z = 0;
};

int main()
{
    Point pt = { 100, 200 };
    cout << pt.x << ", " << pt.y << endl;

    // int x = pt.x;
    // int y = pt.y;
    // C++17, structured binding declaration
    // 1) auto
    // 2) 멤버의 개수와 동일해야 합니다.
    auto [x, y, z] = pt;
    cout << x << ", " << y << endl;

    // 3) 배열에서도 사용할 수 있습니다.
    int arr[3] = { 10, 20, 30 };
    auto [a, b, c] = arr;
    cout << a << ", " << b << ", " << c << endl;
}
