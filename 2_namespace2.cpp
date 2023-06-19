// 2_namespace2.cpp

// 1) C++에서 C의 헤더를 사용할 때,
//    c 접두를 가진 확장자 없는 헤더를 사용해야 합니다.
// 2) C의 모든 함수를 std 이름 공간 안에서 사용할 수 있습니다.

#include <cstdio>
#include <cstdlib>
#include <cstring>

#if 0
namespace std {
#include <stdio.h>
}
#endif

int main()
{
    std::printf("Hello, C\n");
}

#if 0
int main()
{
    xxx::printf("Hello, C\n");
}
#endif
