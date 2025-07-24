/*
    Compile it with `riscv64-unknown-elf-gcc -O0 -S register.c` and try to see in the `register.s` 
    assembly file if the value of 10 will be allocated directly in a register like via the instruction `li s1,10` 
*/

// #include <stdio.h>

void main() {
    register int a = 10;
    a = a + 1;
    // printf("main: %d\n", a);
    return;
}