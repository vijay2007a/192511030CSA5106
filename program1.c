#include <stdio.h>
#include <ctype.h>

void caesarEncrypt(char text[], int k) {
    int i = 0;
    while (text[i] != '\0') {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            text[i] = (char)(base + (ch - base + k) % 26);
        }

        i++;
    }
}

int main() {
    char text[1000];
    int k;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25) {
        printf("Key must be between 1 and 25.\n");
        return 1;
    }

    caesarEncrypt(text, k);

    printf("Encrypted message: %s", text);
    return 0;
}
