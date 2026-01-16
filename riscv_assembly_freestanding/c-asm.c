void glenio()
{
    // As we're only assigning values that can be represented by 8 bits, you might see that when these values are loaded
    // into a CPU registers (which have 32 bits each because we're running with the rv32i architecture), all the bits
    // that are not used (32 - 8 = 24 bits to the left) will be 0 if we're using `int` as the variable type. You can see
    // this by running this code with QEMU and checking the registers with GDB.
    // Also change the variables to the char type later (e.g. char a = 0xA1) and see how the bitwise operations work.
    // The left bits in the registers might end up being filled with 1s instead of 0s. This might happen when you have
    // values are assigned to a char where the MSB is 1, which is the case for 0xA1 below. Then, all the left bits
    // will be filled with 1s (meaning that the RISC-V CPU just replicated the MSB to the left bits).
    int a = 0xA1; // the value represents 8 bits: 1010 0001
    int b = 0x52; // the value represents 8 bits: 0101 0010
    int c = 0x0;

    c = a & b;
    c = 0x0;

    c = a | b;
    // doing c = 0 to clear the register between operations
    c = 0;

    c = a ^ b;
    c = 0;

    c = ~a;
    c = 0;

    c = ~b;
    c = 0;
}