#include <stdio.h>

typedef unsigned int glenio;

void main() {
    glenio a = 10;
    int size = sizeof(a);
    printf("%d\n", size);

    // we can still use unsigned int, as typedef only creates an alias to it, it doesn't replace the type itself
    unsigned int b = 21;
    size = sizeof(b);
    printf("%d\n", size);

    size = sizeof(int);
    printf("%d\n", size);
}