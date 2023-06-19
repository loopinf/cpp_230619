// main.c
#include <stdio.h>

#include "add.h"

// __Z3foov
void _Z3foov(void);

int main(void)
{
    int result = add(10, 20);
    printf("result: %d\n", result);

    _Z3foov();

    return 0;
}
