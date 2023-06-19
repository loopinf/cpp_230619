// 9_함수.cpp
#include <iostream>
using namespace std;

// 파라미터 기본값을 지정할 수 있습니다.
// => 기본 파라미터
// 정의: 함수에 전달된 인자가 없는 경우,
//      컴파일러가 기본값을 자동으로 전달합니다.

// 주의사항
// 1) 반드시 마지막 파라미터부터 지정해야 합니다.
// 2) 선언부에 작성되어야 합니다.

int Add(int a, int b, int c = 0, int d = 0);

int main()
{
    cout << Add(10, 20, 30, 40) << endl;

    cout << Add(10, 20, 30) << endl;
    //      Add(10, 20, 30, 0)

    cout << Add(10, 20) << endl;
    //      Add(10, 20, 0, 0)
}

int Add(int a, int b, int c /* =0 */, int d /* =0 */)
{
    return a + b + c + d;
}
