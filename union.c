#include <stdio.h>

union xyz
{
    int a;
    char b;
    float c;
};

union xy
{
    int a;
    unsigned int b;
};

union xy2
{
    int a;
    char b;
};

int main()
{
    // === Checking union size
    union xyz u;

    // the bytes allocated in memory will be equal to the highest space needed, in this case, the float = 4 bytes
    printf("sizeof(u): %ld\n", sizeof(u));

    // essentialy, each member's start address will be the same because the address is reserved for the whole union to acommodate one or another of these values.
    // This is in contrast to a struct where each member will have a different start address and the total size of a struct will be total sum of each individual member size.
    printf("&(u.a): %p\n", &(u.a));
    printf("&(u.b): %p\n", &(u.b));
    printf("&(u.c): %p\n", &(u.c));

    // === Checking union values
    printf("=======\n");

    union xy v;

    v.a = -1;

    // here we can see that even though 'b' is an unsigned int, if we assign 'a = -1', we're basically assigning this value to the union, so 'b' should
    // also have the same value, that is, -1. So, be careful, because the code will compile but at runtime 'b' might not have an unsigned int.
    printf("%d\n", v.b);

    // === Checking union values with endianess
    printf("=======\n");

    union xy2 z;

    z.a = 0xFF000041;
    printf("z.a: %x\n", z.a);

    // 'b' will have the same value as 0xFF000041. However, if we try to print it as a character '%c', it'll only read the first byte out of this value. If the system
    // is using Little Endian to store the value, it'll store in memory the inverted order of what will provide, which is: 0x41 0x00 0x00 0xFF. When reading the first
    // byte then, it'll read 0x41, which is the letter 'A' in the ASCII table (in the hexadecimal format).
    printf("z.b: %c\n", z.b);

    // Now, if we add 1 to the z.a, which will also propagate to z.b, and if the system is Little Endian, 'b' will now have '0x41 + 1', which is now the letter B (0x42)
    // when printed as a character.
    z.a = z.a + 1;
    printf("z.b: %c\n", z.b);

    return 0;
}