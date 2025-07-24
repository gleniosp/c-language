#include <stdio.h>

union myunion_t {
    long a;
    float b;
};

void main() {
    union myunion_t p;

    printf("%ld\n", sizeof(union myunion_t));
}