// you can compile this file with: gcc global.c extern.c

#include <stdio.h>

// // variables defined outside a scope has a global like scope across the whole file
// int a = 10;

/* we could also just compile this file with the extern.c file which also contains a definition of "a", and  
reference "a" here witth an "extern" keyword, which would cause the same global like scope behavior */
extern int a;

// it also works for a function
extern void foo();

void main() {
    a = a + 1;
    printf("main: %d\n", a);

    foo();
    return;
}