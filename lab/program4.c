#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenereEncrypt(char text[], const char *key) {
    int keyLen = (int)strlen(key);
    int j = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            char keyChar = toupper((unsigned char)key[j % keyLen]);
            int shift = keyChar - 'A';
            text[i] = (char)(base + ((text[i] - base + shift) % 26));
            j++;
        }
    }
}

int main(void) {
    char text[1000];
    char key[100];

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    vigenereEncrypt(text, key);
    printf("Encrypted message: %s\n", text);
    return 0;
}
