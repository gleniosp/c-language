#include <stdio.h>

int main() {
    int a = 9;
    int b = 4;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);

    // a++ = use first and then increment
    printf("a++ = %d\n", a++);
    // ++a = increment first then use
    printf("++a = %d\n", ++a);

    printf("b-- = %d\n", b++);
    printf("--b = %d\n", --b);

    char c = 127;
    char d = 4;

    // this will implicitly convert the values to integer before printing them
    printf("c + d = %d\n", c + d);
    // we explicitly cast to char
    printf("c + d = %d\n", (char)(c + d));

    printf("c++ = %d\n", c++);
    // we can see how this will overflow, as char is 8-bits signed
    printf("++c = %d\n", ++c);

    return 0;
}