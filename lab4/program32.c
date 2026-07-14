#include <stdio.h>

int main(void) {
    printf("DSA uses a fresh random k for each signature, so repeated signing of the same message produces different signatures. RSA signatures, by contrast, are deterministic for the same message and key.\n");
    return 0;
}
