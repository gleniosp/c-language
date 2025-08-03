#include <stdio.h>

int main() {
    short int a_short[5] = {10, 20, 30, 40, 50};
    int a_int[5] = {11, 21, 31, 41, 51};

    /* check the size of the arrays */
    printf("sizeof(a_short): %ld\n", sizeof(a_short));
    printf("sizeof(a_int): %ld\n", sizeof(a_int));
    
    /* assign and read array values */
    a_int[3] = 45;
    printf("a_int[3]: %d\n", a_int[3]);

    int i = 0;
    while (i < 5) {
        printf("a_int[%d]: %d\n", i, a_int[i]);
        i = i + 1;
    }

    int x = 99;
    printf("x: %d\n", x);

    x = a_int[4];
    printf("x: %d\n", x);

    /* showing that accessing out of bound indexes can affect other variables in the memory close to the array */
    int y[2] = {1, 2};
    int int_array[2] = {11, 21};
    int z[2] = {8, 9};

    int_array[2] = 101;

    printf("y[0] = %d\n", y[0]);
    // if z is allocated after int_array in memory and we try to access and write to an 3rd element in int_array (which is out of bound), 
    // it might affect the first element of z which is right after the end of int_array in memory. So, the below statement
    // would print 101, showing that int_array[2] = 101 affected z[0] in memory. This is a dangerous situation in C and the programmer should be careful with this behaviour.
    printf("z[0] = %d\n", z[0]);

    return 0;
}