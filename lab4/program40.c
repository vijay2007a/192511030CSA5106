#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int scoreText(const char *text) {
    const char *freq = "ETAOINSHRDLCUMWFGYPBVKXJQZ";
    int score = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha((unsigned char)text[i])) {
            char ch = toupper((unsigned char)text[i]);
            for (int j = 0; freq[j] != '\0'; ++j) {
                if (ch == freq[j]) {
                    score += 26 - j;
                    break;
                }
            }
        }
    }
    return score;
}

int main(void) {
    char ciphertext[] = "QEBOBDHB";
    char plaintext[100];
    int bestScore = -1;

    for (int shift = 0; shift < 26; ++shift) {
        for (int i = 0; ciphertext[i] != '\0'; ++i) {
            if (isalpha((unsigned char)ciphertext[i])) {
                char base = isupper((unsigned char)ciphertext[i]) ? 'A' : 'a';
                int p = (ciphertext[i] - base - shift + 26) % 26;
                plaintext[i] = (char)(base + p);
            } else {
                plaintext[i] = ciphertext[i];
            }
        }
        plaintext[strlen(ciphertext)] = '\0';
        int score = scoreText(plaintext);
        if (score > bestScore) {
            bestScore = score;
            printf("Shift %d -> %s\n", shift, plaintext);
        }
    }
    return 0;
}
