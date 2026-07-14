#include <stdio.h>

int main(void) {
    printf("Encrypting each letter separately with RSA is insecure because the plaintext values are small and the same public key is reused. A common attack is to exploit the small plaintext space and use frequency or brute-force methods.\n");
    return 0;
}
