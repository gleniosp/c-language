#include <stdio.h>

int main() {
    char *str = "Glenio";
    char x[] = {'G', 'l', 'e', 'n', 'i', 'o', '\0'};
    char y[] = "Glenio";

    printf("str: %s\n", str);
    printf("x  : %s\n", x);
    printf("y  : %s\n", y);

    return 0;
}