#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[]) {
    char number[101];
    scanf("%s", number);
    int i = 0, j;
    int num = 0;
    int ispoint = 0;
    int flag = 1;
    char ans[100] = "";
    if (i == 0 && number[i] == '0') {
        for (i = 0; i < strlen(number); ++i) {
            flag = 0;
            if (number[i] == '0') {
                num++;
            }
            if (number[i] != '0' && number[i] != '.') {
                int tmp = i;
                for (j = 0; j <= strlen(number) - tmp; ++j) {
                    if (j == 1 && strlen(number) - tmp > 1)
                    {
                        ans[j] = '.';
                        continue;
                    }
                    ans[j] = number[i++];
                }
                break;
            }
        }
    } else {
        j = 0;
        for (i = 0; i < strlen(number); ++i) {
            if (number[i] == '.') {
                ispoint = 1;
                continue;
            }
            if (j==1 && strlen(number) > 1)
            {
                ans[j++] = '.';
            }
            ans[j++] = number[i];
            if (i > 0 && ispoint == 0) {
                num++;
            }
        }
    }
    if (flag == 1)
        printf("%se%d", ans, num);
    else
        printf("%se-%d", ans, num);
    return 0;
}