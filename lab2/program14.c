#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void encryptOneTimePad(char *text, int *key, int len) {
    for (int i = 0; i < len; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            int p = toupper((unsigned char)text[i]) - 'A';
            int c = (p + key[i]) % 26;
            text[i] = (char)(base + c);
        }
    }
}

int main(void) {
    char plaintext[] = "SENDMOREMONEY";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int len = (int)strlen(plaintext);
    char ciphertext[100];

    strcpy(ciphertext, plaintext);
    encryptOneTimePad(ciphertext, key, len);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
