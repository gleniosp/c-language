// compile this with: gcc static.c static_aux.c

#include <stdio.h>

extern int a;

void foo();

void bar() {
    static char b = 3;
    b = b + 1;

    printf("bar: %d\n", b);
}

void main() {
    a = a + 1;
    printf("main: %d\n", a);

    foo();
    bar(); // b = 4 here
    bar(); // b = 5 here, because b will keep its previous state within the bar function across function calls
    return;
}