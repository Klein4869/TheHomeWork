#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct wordtree
{
    int ascii;
    char word;
    int num;
    char value[30];
    struct wordtree *left;
    struct wordtree *right;
};

int null_num = 0;
char code[300] = {0};
char x[2000] = {0};

void encode(struct wordtree *head){
    int j;
    if (head == NULL)
        return;
    for (j = 0; j < 30; ++j) {
        head->value[j] = '\0';
    }
    strcat(head->value, code);
    strcat(code, "0");
    encode(head->left);
    code[strlen(code)-1] = '\0';
    strcat(code, "1");
    encode(head->right);
    code[strlen(code)-1] = '\0';
}

void print_code(struct wordtree *head, char x1){
    if (head == NULL)
        return;
    if (head->word == x1) {
//        printf("%d %s\n",x1,head->value);
        strcat(x, head->value);
        return;
    }
    print_code(head->left, x1);
    print_code(head->right, x1);
}

int main(int argc, char const *argv[])
{
    int i,  counter = 0, j = 0;
    int num[128] = {0};
    num[0] = 1;
    char words1[128];
    int words[128];
    char word_his[1000];
    int temp = 0;
    FILE *fp = fopen("input.txt", "r");
    char c;
    while(!feof(fp)){
        c = fgetc(fp);
        if (c > 127 || c < 0 || c == '\n')
            continue;
        num[c]++;
        word_his[temp++] = c;
    }
    word_his[temp++] = '\0';
    for (i = 0; i < 128; ++i)
    {
        if (num[i]!=0)
        {
            words[counter] = num[i];
            words1[counter++] = i;
        }
    }
    struct wordtree **w = (struct wordtree **)malloc(counter*sizeof(struct wordtree));
    struct wordtree *head;
    for (i = 0; i < counter; ++i)
    {
        w[i] = (struct wordtree *)malloc(sizeof(struct wordtree));
        w[i]->num = words[i];
        w[i]->word = words1[i];
        w[i]->left = NULL;
        w[i]->right = NULL;
        w[i]->ascii = w[i]->word;
    }
    int m = 200;
    for (i = 0; i < counter-1; ++i)
    {
        int min=-1, second_min=-2;
        for (j = 0; j < counter; ++j) {
            if (w[j] == NULL)
                continue;
            if (min == -1) {
                min = j;
                continue;
            }
            if (second_min == -2) {
                second_min = j;
                break;
            }
        }
        for (j = second_min; j < counter; ++j) {
            if (w[j] == NULL)
                continue;
            if (w[j]->num < w[min]->num){
                second_min = min;
                min = j;
                continue;
            }
            if (w[j]->num == w[min]->num && w[j]->ascii < w[min]->ascii){
                second_min = min;
                min = j;
                continue;
            }
            if (w[j]->num < w[second_min]->num){
                second_min = j;
                continue;
            }
            if (w[j]->num == w[second_min]->num && w[j]->ascii < w[second_min]->ascii){
                second_min = j;
            }
        }
        head = (struct wordtree *)malloc(sizeof(struct wordtree));
        head->ascii = m++;
        head->word = -1;
        if (w[second_min]->num == w[min]->num && w[min]->ascii > w[second_min]->ascii){
            head->left = w[second_min];
            head->right = w[min];
        } else {
            head->left = w[min];
            head->right = w[second_min];
        }
        head->num = w[min]->num + w[second_min]->num;
        w[min] = head;
        w[second_min] = NULL;
        null_num++;
    }
    free(w);
    encode(head);
    for (i = 0; i < temp; ++i) {
        print_code(head, word_his[i]);
    }
    while (strlen(x) % 8){
        strcat(x, "0");
    }
    unsigned long long ans, diedai = 1;
    for (j = 0; j < strlen(x)/8; ++j) {
        ans = 0;
        diedai = 1;
        for (i = 7; i >= 0; --i) {
            ans += diedai * (x[j*8 + i] - '0');
            diedai *= 2;
        }
        printf("%x", ans);
    }
    fclose(fp);
    // fp = fopen("output.txt", "w");
    // int c1 = 0;
    // int bits = 0;
    // for (i = 0; i < strlen(x); ++i) {
    //     c1 <<= 1;
    //     if (x[i] == '1'){
    //         c1 += 1;
    //     }
    //     bits++;
    //     if (bits%8 == 0){
    //         fputc(c1,fp);
    //         c1 = 0;
    //     }
    // }
    return 0;
}