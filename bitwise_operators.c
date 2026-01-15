// run with: gcc bitwise_operators.c && ./a.out

#include <stdio.h>

int main()
{
    int a = 0xA1; // the value represents 8 bits: 1010 0001
    int b = 0x52; // the value represents 8 bits: 0101 0010

    printf("& : 0x%x\n", a & b);
    printf("| : 0x%x\n", a | b);
    printf("^ : 0x%x\n", a ^ b);
    // As `int` has 32 bits, and we're filling only 8 of them with our value, all other bits will be 0. When `~` is applied, they will all become 1.
    // That's why we see the printf below printing a bunch of `f` values on the left side, because every time we have `1111` in sequence, this is a `f` in hexadecimal.
    printf("~a : 0x%x\n", ~a);
    printf("~b : 0x%x\n", ~b);

    printf("\n\n");

    long int c = 0xA1; // the value represents 8 bits: 1010 0001
    long int d = 0x52; // the value represents 8 bits: 0101 0010

    printf("& : 0x%lx\n", c & d);
    printf("| : 0x%lx\n", c | d);
    printf("^ : 0x%lx\n", c ^ d);
    // Same explanation as for the `int` variables above. However, as they're `long` variables now, we'll 64 bits and a bunch of `f` values more than the 32 bits case.
    // You can see that the machine running the code within GitHub codespaces is a 64-bit machine, for example, by doing `file a.out` in the terminal.
    // This will print a string like `a.out: ELF 64-bit LSB shared object...`. That's why a `long` represents 64 bits on this machine.
    printf("~c : 0x%lx\n", ~c);
    printf("~d : 0x%lx\n", ~d);

    return 0;
}