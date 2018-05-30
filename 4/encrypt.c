#include "stdio.h"
#include "string.h"

int main() {
    char key[35];
    int i = 0, j;
    char temp_char;
    while ((temp_char = getchar()) != '\n') {
        key[i++] = temp_char;
    }

    for (i = 0; i < strlen(key) - 1; ++i) {
        for (j = i + 1; j < strlen(key); ++j) {
            if (key[j] == key[i]) {
                key[j] = 1;
            }
        }
    }
    int k;
    i = 0;
    char newkey[35];
    for (k = 0; k < strlen(key); ++k) {
        if (key[k] != 1) {
            newkey[i++] = key[k];
        }
    }
    newkey[i] = '\0';

    char circle[200];
    char new_circle[200];

    for (k = 0; k < i; ++k) {
        circle[k] = newkey[k];
    }
    for (; k <= i + 126 - 32; ++k) {
        if (k == i + 93) {
            int f = 0;
        }
        circle[k] = k - i + 32;
    }
    circle[k] = '\0';
    for (i = 0; i < strlen(newkey); ++i) {
        for (j = i + 1; j < strlen(circle); ++j) {
            if (circle[j] == circle[i]) {
                circle[j] = 1;
            }
        }
    }
    i = 0;
    for (k = 0; k < strlen(circle); ++k) {
        if (circle[k] != 1) {
            new_circle[i++] = circle[k];
        }
    }

    for (k = 0; k < strlen(new_circle); ++k) {
        circle[k] = new_circle[k];
    }

    circle[k] = '\0';

    int l = 0;

    int num = i;

    int sum = i;

    int counter;

    i = 0;

    int flag;

    char first_key = new_circle[i];
    char new_circle1[150];

    while (num-- > 1) {
        counter = 0;
        int flag = i;
        int count = new_circle[flag];
        if (new_circle[flag] == 1)
            while (new_circle[i] == 1 && i < sum) {
                i++;
                if (i > sum - 1) {
                    i = i - sum;
                }
            }
        flag = i;
        count = new_circle[flag];
        new_circle[flag] = 1;
        while (1) {
            while (new_circle[i] < 32 && i < sum) {
                i++;
                if (i > sum - 1) {
                    i = i - sum;
                }
            }
            if (new_circle[i] == 1) {
                printf("你的跳过函数有问题\n");
            }
            counter++;
            if (counter == count) {
                new_circle1[flag] = new_circle[i];

                break;
            }
            if (i == sum - 1) {
                i = 0;
            } else {
                i++;
            }
        }
    }

    for (i = 0; i < sum; ++i) {
        if (new_circle[i] != 1) {
            new_circle1[i] = first_key;
            break;
        }
    }


    FILE *fp = fopen("in.txt", "r");
    FILE *fp1 = fopen("in_crpyt.txt", "w");
    char t;
    int m;
    while ((t = fgetc(fp)) != EOF) {
        int flag = 0;
        if (t == '\n') {
            fputc(t, fp1);
            continue;
        }
        for (m = 0; m < sum; ++m) {
            if (circle[m] == t) {
                fputc(new_circle1[m], fp1);
                flag = 1;
            }
        }
        if (flag == 0) {
            fputc(t, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
}