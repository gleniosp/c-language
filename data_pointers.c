#include <stdio.h>

int main() {
    // check pointer definition, how to assign an address and value to it and see its size as well.
    char abc = 'Z';
    char *ptr;

    ptr = &abc;

    printf("&abc: %p, ptr: %p, sizeof(ptr): %ld\n", &abc, ptr, sizeof(ptr));

    printf("*ptr: %c, abc: %c\n", *ptr, abc);

    *ptr = 'A';

    printf("*ptr: %c, abc: %c\n", *ptr, abc);

    printf("======\n");

    // checking pointer addresses and values
    char number[4];

    int *in_ptr;
    in_ptr = &number[0];

    // the number array wasn't initialized yet. So, assigning it to the pointer and printing the pointed value as an integer 
    // will make the pointer read all 4 bytes from the number array (4 values of 1 byte each because its made of chars) 
    // and convert these 4 bytes to an integer to print them. It'll be a random garbage value because we didn't initialize the char array with anything.
    printf("in_ptr: %p\n", in_ptr);
    printf("*in_ptr: %d\n", *in_ptr);

    *in_ptr = 65;

    // here we can see that we can print the pointed value as an integer or a char (if the integer value can be mapped to an ASCII table value).
    printf("*in_ptr as integer: %d, *in_ptr as char: %c\n", *in_ptr, *in_ptr);

    printf("======\n");

    // note that by assigning 65 to the in_ptr before, we also updated the first element in the array. All other 3 bytes for the array might have some other random value,
    // which sometimes is zero (but don't trust on it being zero).
    int i = 0;
    while (i < 4) {
        printf("%c\n", number[i]);
        i = i + 1;
    }

    printf("======\n");

    // now if we update *in_ptr again to have the correspondent HEX values of "HI!" in the ASCII table, which are 0x48 0x49 and 0x21 and 0x00 (null character) 
    // to close the "string", we can also loop through them to check and print them as individual characters. Note that the null character will be print as well and
    // appear blank on the terminal
    //
    // besides, if the printing order is "HI! " it is because the bytes are stored in memory in the Big Endian representation. That is, the MSB (most significant byte) 
    // is placed in the lowest address of the array. So, when the pointer reads the first position pointed by it, it'll read the "H" character first as in the same order 
    // that we assigned it to the *in_ptr pointer. However, if it prints " !IH", that is, the inverse order, that is because our machine is storing the bytes in the 
    // Little Endian representation. So, the LSB (Least significant byte) is stored in the lowest address of the array.
    *in_ptr = 0x48492100;
    i = 0;
    while (i < 4) {
        printf("%c\n", number[i]);
        i = i + 1;
    }

    // and we can also print the whole string at once. Essentially, get the first element in the array we treat the rest of teh array as a string and print it 
    // (which is what the %s is doing in the printf). Note that if the system uses Little Endian we try to print 0x48492100, the first character will the the null
    // one (0x00), so printf will simply print a blank space and stop there, because it reached the null character. In this case, we should do *in_ptr = 0x00214948, so
    // when it is stored with the Little Endian representation, it prints 0x48 first until it reaches the 0x00.
    printf("======\n");
    *in_ptr = 0x48492100;
    printf("%s\n", &number[0]); // this might print blank if the system uses Little Endian representation

    *in_ptr = 0x00214948;
    printf("%s\n", &number[0]); // this might print blank if the system uses Big Endian representation

    return 0;
}