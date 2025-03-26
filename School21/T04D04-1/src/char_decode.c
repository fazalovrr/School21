#include <stdio.h>

int coding(char ch[256]) {
    int i = 0, b, flag = 0, j = 0;

    while (ch[i] != '\0' && flag < 2) {
        b = ch[i];
        if (flag == 0) {
            if (b > 32 && b < 126) {
                flag = 1;
            } else {
                flag = 2;
            }
        } else if (flag == 1) {
            {
                if (b == 32 || b == 10)
                    flag = 0;
                else
                    flag = 3;
            }
        }
        i++;
    }

    if (flag > 1) {
        printf("n/a");
    } else {
        for (j = 0; j < i; j++) {
            b = ch[j];
            if (b > 32 && b < 126 && j > 0) printf(" %X", b);
            if (b > 32 && b < 126 && j == 0) printf("%X", b);
        }
    }
    return 0;
}

int decoding(char ch[256]) {
    int i = 0, b, flag = 0, j = 0;
    char h[3];
    h[0] = ch[0];
    h[1] = ch[1];
    h[2] = '\0';

    while (ch[i] != '\0' && flag < 2) {
        b = ch[i];
        if (flag == 0)
            if ((b >= 48 && b <= 57) || (b >= 65 && b <= 70) || (b >= 97 && b <= 102)) {
                i++;
                b = ch[i];
                if ((b >= 48 && b <= 57) || (b >= 65 && b <= 70) || (b >= 97 && b <= 102))
                    flag = 1;
                else
                    flag = 2;
            } else
                flag = 22;
        else if (flag == 1) {
            if (b == 32 || b == 10)
                flag = 0;
            else
                flag = 3;
        }
        i++;
    }
    if (flag > 1)
        printf("n/a");
    else
        while (j < i) {
            b = ch[j];
            if ((b >= 48 && b <= 57) || (b >= 65 && b <= 70) || (b >= 97 && b <= 102)) {
                h[0] = ch[j];
                h[1] = ch[j + 1];
                h[2] = '\0';
                sscanf(h, "%02X", &b);
                if (j > 0)
                    printf(" %c", (char)b);
                else
                    printf("%c", (char)b);
                j++;
            }
            j++;
        }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc == 2 && (argv[1][0] == '1' || argv[1][0] == '0')) {
        char ch[256];

        if (fgets(ch, sizeof(ch), stdin) != NULL) {
            if (argv[1][0] == '0') coding(ch);
            if (argv[1][0] == '1') decoding(ch);
        }
    } else {
        printf("%s", "Missing params! Enter params: 0 - for codinf / 1 - for decoding");
    }
    return 0;
}