#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void buildMatrix(const char *keyword, char matrix[5][5]) {
    int used[26] = {0};
    char temp[100];
    int index = 0;

    for (int i = 0; keyword[i] != '\0'; ++i) {
        char ch = toupper((unsigned char)keyword[i]);
        if (ch == 'J') ch = 'I';
        if (isalpha((unsigned char)ch)) {
            int pos = ch - 'A';
            if (!used[pos]) {
                used[pos] = 1;
                temp[index++] = ch;
            }
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (ch == 'J') continue;
        int pos = ch - 'A';
        if (!used[pos]) {
            temp[index++] = ch;
            used[pos] = 1;
        }
    }

    for (int i = 0; i < 25; ++i) {
        matrix[i / 5][i % 5] = temp[i];
    }
}

static void prepareText(const char *plain, char *prepared) {
    int j = 0;
    for (int i = 0; plain[i] != '\0'; ++i) {
        char ch = toupper((unsigned char)plain[i]);
        if (ch == 'J') ch = 'I';
        if (isalpha((unsigned char)ch)) {
            if (j > 0 && prepared[j - 1] == ch) {
                prepared[j++] = 'X';
            }
            prepared[j++] = ch;
        }
    }
    if (j % 2 != 0) {
        prepared[j++] = 'X';
    }
    prepared[j] = '\0';
}

static void locate(char matrix[5][5], char ch, int *row, int *col) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

static void encryptPair(char matrix[5][5], char a, char b, char *out1, char *out2) {
    int r1, c1, r2, c2;
    locate(matrix, a, &r1, &c1);
    locate(matrix, b, &r2, &c2);

    if (r1 == r2) {
        *out1 = matrix[r1][(c1 + 1) % 5];
        *out2 = matrix[r2][(c2 + 1) % 5];
    } else if (c1 == c2) {
        *out1 = matrix[(r1 + 1) % 5][c1];
        *out2 = matrix[(r2 + 1) % 5][c2];
    } else {
        *out1 = matrix[r1][c2];
        *out2 = matrix[r2][c1];
    }
}

int main(void) {
    char keyword[100];
    char plaintext[1000];
    char prepared[1000];
    char matrix[5][5];
    char ciphertext[1000];

    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    buildMatrix(keyword, matrix);
    prepareText(plaintext, prepared);

    int index = 0;
    for (int i = 0; prepared[i] != '\0'; i += 2) {
        char a = prepared[i];
        char b = prepared[i + 1];
        char out1, out2;
        encryptPair(matrix, a, b, &out1, &out2);
        ciphertext[index++] = out1;
        ciphertext[index++] = out2;
        ciphertext[index++] = ' ';
    }
    ciphertext[index] = '\0';

    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
