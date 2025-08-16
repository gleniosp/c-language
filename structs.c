#include <stdio.h>

struct complex_num
{
    float a;
    float b;
};

int main()
{
    struct complex_num cnum = {100, 200};

    printf("a = %f, b = %f\n", cnum.a, cnum.b);

    cnum.a = 10;
    cnum.b = 20;

    // it should print 8 bytes, because which float is 4 bytes and the struct has the size of all of its individual data types
    printf("sizeof(struct complex_num) = %ld\n", sizeof(struct complex_num));
    printf("a = %f, b = %f\n", cnum.a, cnum.b);

    return 0;
}