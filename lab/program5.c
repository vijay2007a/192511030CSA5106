#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int modInverse(int a) {
    for (int x = 1; x < 26; ++x) {
        if ((a * x) % 26 == 1) {
            return x;
        }
    }
    return -1;
}

static int isValidA(int a) {
    int values[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    for (int i = 0; i < 12; ++i) {
        if (values[i] == a) return 1;
    }
    return 0;
}

void affineEncrypt(char text[], int a, int b) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            int p = text[i] - base;
            int c = (a * p + b) % 26;
            text[i] = (char)(base + c);
        }
    }
}

void affineDecrypt(char text[], int a, int b) {
    int inv = modInverse(a);
    if (inv == -1) return;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            int c = text[i] - base;
            int p = (inv * (c - b + 26)) % 26;
            text[i] = (char)(base + p);
        }
    }
}

int main(void) {
    char text[1000];
    int a, b;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter a (1,3,5,7,9,11,15,17,19,21,23,25): ");
    scanf("%d", &a);
    printf("Enter b (0-25): ");
    scanf("%d", &b);

    if (!isValidA(a) || b < 0 || b > 25) {
        printf("Invalid affine key.\n");
        return 1;
    }

    affineEncrypt(text, a, b);
    printf("Encrypted message: %s\n", text);
    return 0;
}
