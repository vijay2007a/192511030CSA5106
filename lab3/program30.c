#include <stdio.h>
#include <string.h>

int main(void) {
    unsigned char x[] = {0x41, 0x42, 0x43, 0x44};
    unsigned char t[] = {0x10, 0x20, 0x30, 0x40};
    unsigned char y[4];

    for (int i = 0; i < 4; ++i) y[i] = x[i] ^ t[i];
    printf("CBC-MAC style tag generated for the two-block message.\n");
    for (int i = 0; i < 4; ++i) printf("%02X ", y[i]);
    printf("\n");
    return 0;
}
