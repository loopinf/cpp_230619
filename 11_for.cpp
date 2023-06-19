// 11_for.cpp
#include <iostream>
using namespace std;

int main()
{
    int x[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; ++i) {
        cout << x[i] << endl;
    }

    // C++11, Ranged-for
    for (auto e : x) {
        cout << e << endl;
    }
}
