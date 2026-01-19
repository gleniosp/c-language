// run with: gcc bitwise_operators_2.c && ./a.out

#include <stdio.h>

int main()
{
    /** LEFT SHIFT OPERATION */

    long int a = 0x1; // equivalent to '.... 0001' in bits

    // It will print 0x8 in hex, equivalent to '.... 1000' in bits as the LSB has shifted 3 positions to the left.
    //
    // Also, when we shift to the left, we're also multiplying by 2^(total shift). So, in this case, by moving the value 1 to the left by 3 positions
    // we're doing 1 x 2^3 = 1 x 8 = 8. We basically multiplied the value by 2, and 3 times.
    printf("a << 3: 0x%lx\n", a << 3);

    // It will print 0x8000000000000000 in hex, equivalent to '1000 ...' in bits, that is, the LSB has shifted 63 bits to the left
    // in this 64 bits long int, making it occupying the MSB position.
    printf("a << 63: 0x%lx\n", a << 63);

    // It will print 0x1 in hex, equivalent to '... 0001' in bits, that is, the LSB has shifted 64 bits to the left
    // in this 64 bits long int, so it moved 1 bit beyond the limit of this long int (because the MSB is in the 63 bit position
    // as we start counting from the 0 position, making 64 bits in total), which would make it overflow.
    // However, in some machines, instead of overflowing, it was rotated to the beginning of the 64 bits sequence,
    // ending up in the first bit position (LSB), which is the same as the value 1. In other machines you may simply see a 0x0 response
    // when overflowing or something else.
    //
    // The compiler will also warns us with a message like: left shift count >= width of type [-Wshift-count-overflow].
    // SO, AS A RULE OF THUMB, NEVER USE SHIFT OPERATIONS OUTSIDE THE CURRENT BOUNDS.
    printf("a << 64: 0x%lx\n", a << 64);

    // Same logic as the previous example. It will print 0x2 in hex, equivalent to '... 0010' in bits, that is, the LSB has shifted 65 bits to the left
    // in this 64 bits long int, so it moved 2 bits beyond the limit of this long int, which would make it overflow.
    // However, in some machines, instead of overflowing, it was rotated to the beginning of the 64 bits sequence,
    // ending up in the second bit position, which is the same as the value 2. In other machines you may simply see a 0x0 response
    // when overflowing or something else.
    //
    // The compiler will also warns us with a message like: left shift count >= width of type [-Wshift-count-overflow].
    // SO, AS A RULE OF THUMB, NEVER USE SHIFT OPERATIONS OUTSIDE THE CURRENT BOUNDS.
    printf("a << 65: 0x%lx\n", a << 65);

    /** RIGHT SHIFT OPERATION */

    long int b = 0x8;

    // It will print 0x4 in hex, equivalent to '.... 0100' in bits as 1 bit in the 4th position has shifted 1 position to the right.
    //
    // Also, when we shift to the right, we're also dividing by 2^(total shift). So, in this case, by moving the value 8 to the right by 1 position
    // we're doing 8 / 2^1 = 8 / 2 = 4. We basically divided the value by 2, and 1 time only.
    printf("b >> 1: 0x%lx\n", b >> 1);

    // It will print 0x0. So, when pushing to the right beyond the current bounds, it'll simply return 0x0 in this machine.
    printf("b >> 5: 0x%lx\n", b >> 5);

    // It will print 0x1. As '0x4....' in hex is '0100 ...' in bits. As we move the second most significant bit 62 bits positions to the right
    // it'll end up in the first bit position, which is '... 0001' = 0x1 in hex.
    long int c = 0x4000000000000000;
    printf("c >> 62: 0x%lx\n", c >> 62);

    // Now compare the example below with the previous 'long int c' example. I'd expect this to be 0x1 as well, as we're moving 0x8 in hex ('1000 ...' in bits)
    // 63 positions to the right, ending up in the first bit position '... 0001'. However, this is not the case.
    // As the MSB bit is 1 in this case, when we move it to the right, the CPU fills its space with a 1 instead of a 0. And it'll keep filling
    // all the spaces with 1. So, we end up with `1111 .... 1111` (64 bits, each equal to 1), which is 0xffffffffffffffff in hex.
    // This type of shifting is known as https://en.wikipedia.org/wiki/Arithmetic_shift.
    long int d = 0x8000000000000000;
    printf("d >> 63: 0x%lx\n", d >> 63);

    // The Arithmetic shift behaviour we saw with `long int d` only happens for signed variables. For unsigned variables, we'll see the normal
    // https://en.wikipedia.org/wiki/Logical_shift operation, which simply fill spaces with 0s. Like below, which will print 0x1 as expected:
    unsigned long int e = 0x8000000000000000;
    printf("e >> 63: 0x%lx\n", e >> 63);

    /** MULTIPLICATION AND DIVISION */

    // As shifting also multiplies and divides a number, we can use it when our CPU/MCU doesn't support native multiplication/division operations.
    // For example, if we want to multiply 3 by 5, we can first shift 3 to the left by 2, which multiplies it by 2^2 and then simply add a 3.
    // This is because multiply by 5 is the same as summing the same number 5 times, or the same as multiplying it by 4 and then summing the same number:
    long int f = 3;
    long int g = (f << 2) + f;

    // This will print 15 (same as 3x5)
    printf("g: %ld\n", g);

    // As another example, dividing can also be helped with the right shift operator. It's a bit trickier though, but you can search some examples.

    return 0;
}