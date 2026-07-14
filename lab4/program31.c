#include <stdio.h>

static unsigned long long leftShiftAndXor(unsigned long long value, int bits, unsigned long long constant) {
    value <<= 1;
    if (value & (1ULL << bits)) value ^= constant;
    return value;
}

int main(void) {
    printf("CMAC subkeys use a left shift and conditional XOR. For 64-bit blocks use constant 0x1B; for 128-bit blocks use 0x87.\n");
    return 0;
}
