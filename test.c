#include <stdio.h>

#if 0
// void foo() { }
void foo(void) { }

#if 0
int main(void)
{
    // foo(10);
    const int c;

    
}
#endif

int main()
{
    char str[32] = "hello";
    const char* p = "hello";

    // p[0] = 'x'; // 미정의 동작
}
#endif

#if 0
void foo(void) { }
int add(int a, int b) { return a + b; }
// 0000000000000004 T _add

int main(void)
{
    printf("Hello, C\n");
}
#endif

int main()
{
    int n = 0;
    ++n;
    // 결과는 증가된 값

    n++;
    // 증가되기 이전의 값
}
