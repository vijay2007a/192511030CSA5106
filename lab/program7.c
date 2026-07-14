#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void decryptSubstitution(char text[]) {
    const char *cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";
    const char *plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char ch = toupper((unsigned char)text[i]);
            for (int j = 0; j < 26; ++j) {
                if (ch == cipher[j]) {
                    text[i] = plain[j];
                    break;
                }
            }
        }
    }
}

int main(void) {
    char text[5000];

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    decryptSubstitution(text);
    printf("Decrypted text: %s\n", text);
    return 0;
}
