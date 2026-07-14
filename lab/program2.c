#include <stdio.h>
#include <ctype.h>
#include <string.h>

static const char *cipherAlphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";

void monoalphabeticEncrypt(char text[]) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char ch = toupper((unsigned char)text[i]);
            int index = ch - 'A';
            text[i] = (char)(isupper((unsigned char)text[i]) ? cipherAlphabet[index] : tolower(cipherAlphabet[index]));
        }
    }
}

int main(void) {
    char text[1000];

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    monoalphabeticEncrypt(text);
    printf("Encrypted message: %s\n", text);
    return 0;
}
