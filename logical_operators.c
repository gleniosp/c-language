#include <stdio.h>

int main()
{
    // as long as both numbers are non-zero, "&&" will return true, which is equivalent to 1 in integer, so "a" will be 1
    int a = -1 && 123;
    int b = 4;

    printf("a = %d\n", a);

    if ((a == b) || (a > b))
    {
        printf("condition met\n");
    }
    else
    {
        printf("condition failed\n");
    }

    printf("%d\n", a && b);
    printf("%d\n", a || b);
    printf("%d\n", !b);

    return 0;
}