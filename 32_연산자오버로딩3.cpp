// 32_연산자오버로딩3.cpp
#include <iostream>
using namespace std;

namespace xstd {
class istream {
public:
    istream& operator>>(int& n)
    {
        scanf("%d", &n);
        return *this;
    }

    istream& operator>>(double& d)
    {
        scanf("%lf", &d);
        return *this;
    }
};

istream cin;
}

int main()
{
    int n;
    // xstd::cin >> n;
    // cin.operator>>(n)

    double d;
    // xstd::cin >> d;

    xstd::cin >> n >> d;
    // cin.operator>>(n).operator>>(d)

    cout << n << endl;
    cout << d << endl;
}
