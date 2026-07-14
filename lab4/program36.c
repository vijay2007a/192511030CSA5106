#include <stdio.h>
#include <ctype.h>

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

int main(void) {
    char text[] = "HELLO";
    affineEncrypt(text, 5, 8);
    printf("Encrypted: %s\n", text);
    return 0;
}
