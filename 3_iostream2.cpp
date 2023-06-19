// 3_iostream2.cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // int n = 0xFAFA;
    // 1111 1010 1111 1010

    // C++11 이진수 상수를 만들 수 있습니다.
    // 단일 따옴표를 통해 구분할 수 있습니다.
    int n = 0b1'11'1'10101'111'1010;

    // IO Manipulator(IO 조정자)
    // : hex, uppercase
    // setw - #include <iomanip>

    printf("%x\n", n);
    cout << hex << n << endl;

    printf("%X\n", n);
    cout << hex << uppercase << n << endl;

    printf("%10d\n", n);
    cout << dec << setw(10) << n << endl;

    printf("%010d\n", n);
    cout << dec << setw(10) << setfill('0') << n << endl;
}
