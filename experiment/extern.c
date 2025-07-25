// for the extern example used in the global.c file

#include <stdio.h>

int a = 10;

void foo() {
    a = a + 1;
    printf("foo: %d\n", a);
    return;
}