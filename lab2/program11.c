#include <stdio.h>
#include <math.h>

int main(void) {
    double approx = 25.0 * 24.0 * 23.0 * 22.0 * 21.0 * 20.0;
    printf("Approximate number of Playfair keys: %.0f\n", approx);
    printf("Approximate power of 2: %.2f\n", log2(approx));
    return 0;
}
