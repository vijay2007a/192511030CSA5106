#include <stdio.h>

int main(void) {
    printf("In ECB mode, a single-bit error affects only one plaintext block. In CBC mode, the error propagates to the next block and can affect subsequent plaintext blocks until the next synchronization point.\n");
    return 0;
}
