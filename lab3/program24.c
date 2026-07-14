#include <stdio.h>

int main(void) {
    int e = 31, n = 3599;
    int phi = 3600 - 1 - 1; 
    int d = 0;
    for (int i = 1; i < phi; ++i) {
        if ((e * i) % phi == 1) {
            d = i;
            break;
        }
    }
    printf("Private key d = %d\n", d);
    return 0;
}
