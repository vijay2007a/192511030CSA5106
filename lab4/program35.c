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
    char text[] = "HELLO";
    int key[] = {3, 19, 5, 7, 11};
    encryptOneTimePad(text, key, (int)strlen(text));
    printf("Encrypted: %s\n", text);
    return 0;
}
