// 5_using.cpp
#include <iostream>
using namespace std;

// using
// 1) namespace
//    using 선언
//        using std::cout;
//    using 지시어
//        using namespace std;

// 2) C++11, typedef를 대체합니다.
//   > 기존 타입의 별칭을 만들 수 있습니다.
//     템플릿의 별칭을 만드는 기능이 using에 도입되었습니다.

//   => typedef는 직관적이지 않습니다.
//    : 변수를 만들 듯이 타입의 별칭을 만들 수 있습니다.

// typedef int N;
// typedef int X[3]; // X == int[3]
// typedef int (*PARR)[3]; // PARR == int (*)[3]

using N = int;
using X = int[3];
using PARR = int (*)[3];

int main()
{
}
