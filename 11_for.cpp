// 11_for.cpp
#include <iostream>
using namespace std;

#include <string>

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

    // 순회 가능한 타입에 대해서 사용할 수 있습니다.
    // - 배열, 문자열(string), 컨테이너
    string s = "hello";
    for (auto& c : s) {
        c = toupper(c);
    }

    for (auto c : s) {
        cout << c << endl;
    }
}
