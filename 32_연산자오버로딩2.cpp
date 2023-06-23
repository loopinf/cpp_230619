// 32_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(char ch)
    {
        printf("%c", ch);
        return *this;
    }
};

ostream cout;

}

int main()
{
    int n = 100;
    xstd::cout << n;

    char ch = 'S';
    xstd::cout << ch;

    xstd::cout << n << ch;
    // xstd::cout.operator<<(n).operator<<(ch)

    // cout << n;
    // cout.operator<<(n);
}
