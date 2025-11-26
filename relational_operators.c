#include <stdio.h>

int main()
{
    char a = 127;
    char b = 4;

    printf("a > b = %d\n", a > b);
    printf("a >= b = %d\n", a >= b);

    printf("a < b = %d\n", a < b);
    printf("a <= b = %d\n", a <= b);

    printf("a == b = %d\n", a == b);
    printf("a != b = %d\n", a != b);

    return 0;
}