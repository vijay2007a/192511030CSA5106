#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void buildKeywordAlphabet(const char *keyword, char *cipher) {
    int used[26] = {0};
    int idx = 0;

    for (int i = 0; keyword[i] != '\0'; ++i) {
        char ch = toupper((unsigned char)keyword[i]);
        if (isalpha((unsigned char)ch)) {
            int pos = ch - 'A';
            if (!used[pos]) {
                used[pos] = 1;
                cipher[idx++] = ch;
            }
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        int pos = ch - 'A';
        if (!used[pos]) {
            cipher[idx++] = ch;
        }
    }
    cipher[idx] = '\0';
}

static void encryptKeywordSubstitution(char text[], const char *cipher) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char ch = toupper((unsigned char)text[i]);
            int pos = ch - 'A';
            text[i] = (char)(isupper((unsigned char)text[i]) ? cipher[pos] : tolower(cipher[pos]));
        }
    }
}

int main(void) {
    char keyword[100];
    char text[1000];
    char cipher[27];

    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    buildKeywordAlphabet(keyword, cipher);
    encryptKeywordSubstitution(text, cipher);
    printf("Ciphertext: %s\n", text);
    return 0;
}
