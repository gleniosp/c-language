#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};

    printf("sizeof a[]: %ld\n", sizeof(a));

    /*
        notice that we're printing more values than the array have, that is, accessing out of bound indexes.
        After a[4], other contiguous memory address will be accessed and they might have gargabe values.
        So, C doesn't block us of accessing out of bound indexes, so we need to be careful with this.
    */
    for (int i = 0; i < 10; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}