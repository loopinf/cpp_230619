#include <stdio.h>

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
