#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesarEncrypt(char text[], int k) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            text[i] = (char)(base + (text[i] - base + k) % 26);
        }
    }
}

int main(void) {
    char text[1000];
    int k;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25) {
        printf("Key must be between 1 and 25.\n");
        return 1;
    }

    caesarEncrypt(text, k);
    printf("Encrypted message: %s\n", text);
    return 0;
}
