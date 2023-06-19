// main.c
#include <stdio.h>

#include "add.h"

int main(void)
{
    int result = add(10, 20);
    printf("result: %d\n", result);

    return 0;
}
