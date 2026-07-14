#include <stdio.h>

int main(void) {
    printf("Reusing the same modulus with a new key pair is not safe if the old private key is leaked, because the modulus can still be attacked with the leaked private key information.\n");
    return 0;
}
