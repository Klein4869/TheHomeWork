#include "stdio.h"
#include "string.h"

int main(int agrc, char const *agrv[]) {
    char x[27];
    scanf("%s", x);
    int isselect[26] = {0};
    char pwdlist[26];
    int i, j, k;
    j = 0;
    for (i = 0; i < strlen(x); ++i) {
        if (isselect[x[i] - 'a'] == 0) {
            pwdlist[j++] = x[i];
            isselect[x[i] - 'a'] = 1;
        }
    }
    for (k = 0; k < 26; ++k) {
        if (isselect[25 - k] == 0) {
            pwdlist[j++] = 'z' - k;
            isselect[25 - k] = 1;
        }
    }

    FILE *fp;
    FILE *fp1;
    fp = fopen("encrypt.txt", "r");
    fp1 = fopen("output.txt", "w");
    char c;
    c = fgetc(fp);
    while (!feof(fp)) {
        if (c - 'a' <= 25 && c - 'a' >= 0) {
            fputc(pwdlist[c - 'a'], fp1);
        } else {
            fputc(c, fp1);
        }
        c = fgetc(fp);
    }

    fclose(fp);
    fclose(fp1);
    return 0;
}