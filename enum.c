#include <stdio.h>

enum xyz
{
    A = 1,
    B,
    C
};

int main()
{
    enum xyz pqr;

    // this will print 1 to 3
    printf("A: %d\n", A);
    printf("B: %d\n", B);
    printf("C: %d\n", C);

    pqr = A;

    // this will print 1
    printf("pqr: %d\n", pqr);

    // As you can see above all fields within the enum becomeb available as their "own" variable.
    // Be careful when creating variables with the same names later in the code as they will "override" the enum variable in the scope, like the example below:

    // int A = 100; // this will override the `A` within the enum

    // printf("A: %d\n", A); // now `A = 100` (from the variable override) instead of `A = 1` (from the enum)

    // this only happens because enum was declared as a global variable (outside main), so the compiler stores the value of `a` for the enum as a global variable
    // and the value of `a` for the local `int a` as a local variable and as we're using later the local value, the compiler "gives preference" to the local variable.
    // If we were to create the enum within the main function and were to declare `int a` as we're doing, the compiler would throw an error saying that we can't
    // redeclare the same variable as different kind of symbol.

    printf("=======\n");

    // it can be used with the switch statement

    switch (pqr)
    {
    case A:
        printf("state: %d\n", pqr);
        break;
    case B:
        printf("state: %d\n", pqr);
        break;
    case C:
        printf("state: %d\n", pqr);
        break;
    default:
        printf("state: %d\n", pqr);
        break;
    }

    return 0;
}