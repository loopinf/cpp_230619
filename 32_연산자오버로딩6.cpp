// 32_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Integer {
    int value;

public:
    Integer(int v = 0)
        : value(v)
    {
    }

    // ++n
    Integer& operator++()
    {
        ++value;
        return *this;
    }

    // n++
    Integer operator++(int)
    {
        Integer temp(*this);
        ++value;

        return temp;
    }

    friend ostream& operator<<(ostream& os, const Integer& n);
};

ostream& operator<<(ostream& os, const Integer& n)
{
    return os << n.value;
}

int main()
{
    int n1 = 42;
    ++n1;
    // 증가된 자기 자신의 참조

    n1++;
    // 증가되기 이전의 값

    cout << n1 << endl;

    Integer n2 = 42;
    ++n2;
    // n2.operator++().operator++()

    n2++;
    // n2.operator++(int)

    cout << n2 << endl;

    // for (int i = 0; i < 10; ++i)
}
