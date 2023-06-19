// 2_namespace3.cpp

// 1) namespace 전체를 명시하는 방법
//   std::cout

#if 0
int main()
{
    std::cout << "Hello, C++" << std::endl;
}
#endif

// 헤더에 작성하면 안됩니다.
// 2) using 선언(declaration)
#if 0
using std::cout;
using std::endl;

int main()
{
    cout << "Hello, C++" << endl;
}
#endif

// 3) using 지시어(directive)
#if 0
using namespace std;
// std 안에 모든 것을 암묵적으로 접근할 수 있습니다.
// > 현업에서 쓰면 안됩니다.

int main()
{
    cout << "Hello, C++" << endl;
}
#endif

#include <iostream>
using std::cout;
using std::endl;
// std::count 라는 함수가 있습니다.

int count = 0;

int main()
{
    count++;

    cout << count << endl;
}
