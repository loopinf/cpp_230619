// 32_연산자오버로딩5.cpp
#include <iostream>

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

    ostream& operator<<(ostream& (*f)(ostream&))
    {
        return f(*this);
    }

    ostream& operator<<(const char* s)
    {
        printf("%s", s);
        return *this;
    }
};

ostream& endl(ostream& os)
{
    os << '\n';
    return os;
}

ostream cout;
}

// 1. endl은 함수 입니다.
// 2. endl을 IO 조정자라고 합니다.

using namespace std;

ostream& menu(ostream& os)
{
    os << "1. 짜장면" << endl;
    os << "2. 짬뽕" << endl;
    os << "3. 탕수육" << endl;
    return os;
}

int main()
{
    // cout << endl;
    cout << menu;

    cout << 42;
    cout << endl;
    // cout.operator<<(endl);

    // endl(cout);
}
