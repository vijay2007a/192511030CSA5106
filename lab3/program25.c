#include <stdio.h>

int main(void) {
    printf("If one plaintext block shares a common factor with n = p*q, then gcd(block, n) reveals p or q, which allows factorization of n and recovery of the private key.\n");
    return 0;
}
