#include <stdio.h>
#include <string.h>

static void xorBytes(unsigned char *a, const unsigned char *b, int len) {
    for (int i = 0; i < len; ++i) a[i] ^= b[i];
}

int main(void) {
    unsigned char iv[4] = {0xAA, 0xAA, 0xAA, 0xAA};
    unsigned char plaintext[4] = {0x01, 0x02, 0x03, 0x04};
    unsigned char key[4] = {0x0F, 0x1F, 0x0D, 0x0A};
    unsigned char ciphertext[4];

    memcpy(ciphertext, plaintext, 4);
    xorBytes(ciphertext, iv, 4);
    for (int i = 0; i < 4; ++i) ciphertext[i] ^= key[i];

    printf("CBC-style sample ciphertext generated.\n");
    for (int i = 0; i < 4; ++i) printf("%02X ", ciphertext[i]);
    printf("\n");
    return 0;
}
