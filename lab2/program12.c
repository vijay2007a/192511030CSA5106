#include <stdio.h>
#include <ctype.h>
#include <string.h>

static void hillEncrypt(char *text, int key[2][2], int n) {
    int len = (int)strlen(text);
    char result[1000];
    int idx = 0;

    for (int i = 0; i < len; i += 2) {
        int a = toupper((unsigned char)text[i]) - 'A';
        int b = (i + 1 < len) ? toupper((unsigned char)text[i + 1]) - 'A' : 0;
        int c = (key[0][0] * a + key[0][1] * b) % 26;
        int d = (key[1][0] * a + key[1][1] * b) % 26;
        result[idx++] = (char)('A' + c);
        result[idx++] = (char)('A' + d);
    }
    result[idx] = '\0';
    strcpy(text, result);
}

static void hillDecrypt(char *text, int key[2][2], int n) {
    int det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    int invDet = -1;
    for (int i = 0; i < 26; ++i) {
        if ((det * i) % 26 == 1) {
            invDet = i;
            break;
        }
    }
    int invKey[2][2] = {
        { (key[1][1] * invDet) % 26, ((-key[0][1]) % 26 + 26) % 26 },
        { ((-key[1][0]) % 26 + 26) % 26, (key[0][0] * invDet) % 26 }
    };

    int len = (int)strlen(text);
    char result[1000];
    int idx = 0;
    for (int i = 0; i < len; i += 2) {
        int a = toupper((unsigned char)text[i]) - 'A';
        int b = (i + 1 < len) ? toupper((unsigned char)text[i + 1]) - 'A' : 0;
        int c = (invKey[0][0] * a + invKey[0][1] * b) % 26;
        int d = (invKey[1][0] * a + invKey[1][1] * b) % 26;
        result[idx++] = (char)('A' + c);
        result[idx++] = (char)('A' + d);
    }
    result[idx] = '\0';
    strcpy(text, result);
}

int main(void) {
    char msg[] = "MEETMEATTHEUSUALPLACEATTENRATHERTHANEIGHTOCLK";
    int key[2][2] = {{9, 4}, {5, 7}};

    hillEncrypt(msg, key, 2);
    printf("Ciphertext: %s\n", msg);

    hillDecrypt(msg, key, 2);
    printf("Recovered plaintext: %s\n", msg);
    return 0;
}
