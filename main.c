#include <stdio.h>

int main() {
    char var1;
    printf("size of var1: %ld\n", sizeof(var1));

    char *var = "Hi";
    printf("size of var: %ld\n", sizeof(var));

    printf("var: %s\n", var);
    printf("Size of Hi: %ld\n", sizeof("Hi"));

    return 0;
}