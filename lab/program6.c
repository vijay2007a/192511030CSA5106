#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int modInverse(int a) {
    for (int x = 1; x < 26; ++x) {
        if ((a * x) % 26 == 1) return x;
    }
    return -1;
}

static int isValidA(int a) {
    int vals[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    for (int i = 0; i < 12; ++i) {
        if (vals[i] == a) return 1;
    }
    return 0;
}

static void toUpperString(char *s) {
    for (int i = 0; s[i] != '\0'; ++i) {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

static int scorePlaintext(const char *text) {
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
    char ciphertext[5000];
    char bestText[5000];
    int bestScore = -1;

    printf("Enter affine ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';
    toUpperString(ciphertext);

    for (int a = 1; a <= 25; ++a) {
        if (!isValidA(a)) continue;
        int inv = modInverse(a);
        if (inv == -1) continue;
        for (int b = 0; b < 26; ++b) {
            char candidate[5000];
            int j = 0;
            for (int i = 0; ciphertext[i] != '\0'; ++i) {
                if (isalpha((unsigned char)ciphertext[i])) {
                    int c = ciphertext[i] - 'A';
                    int p = (inv * (c - b + 26)) % 26;
                    candidate[j++] = (char)('A' + p);
                } else {
                    candidate[j++] = ciphertext[i];
                }
            }
            candidate[j] = '\0';

            int score = scorePlaintext(candidate);
            if (score > bestScore) {
                bestScore = score;
                strcpy(bestText, candidate);
            }
        }
    }

    printf("Most likely plaintext: %s\n", bestText);
    return 0;
}
