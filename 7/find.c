#include <string.h>
#include "stdio.h"

int is_find = 0;
int time = 0;

char words[3600][30];

void bisearch(int first, int last, char *b){
    if(is_find){
        return;
    }
    if (last == first){
        time++;
        if (!strcmp(words[first], b)){
            printf("1 %d", time);
            is_find = 1;
            return;
        } else{
            printf("0 %d", time);
            is_find = 1;
            return;
        }
    }
    int mid = (first+last)/2 + 1;
    time++;
    if (!strcmp(words[mid], b)){
        printf("1 %d", time);
        is_find = 1;
        return;
    }else{
        if(strcmp(words[mid], b) > 0)
            bisearch(first, mid-1, b);
        else
            bisearch(mid+1, last, b);
    }
}

int main() {
    int count = 0, i, compare_num = 0;
    FILE *fp = fopen("/Users/haidongtang/ctest/cmake-build-debug/dictionary3500.txt", "r");
    while (!feof(fp))
        fscanf(fp, "%s", words[count++]);
    char word[30];
    scanf("%s", word);
    char method;
    method = getchar();
    while (method == ' '){
        method = getchar();
    }
    if (method == '1') {
        for (i = 0; i < count; ++i) {
            if (!strcmp(word, words[i]) || strcmp(words[i], word) > 0) {
                printf("1 %d\n", ++compare_num);
                break;
            }
            else
                compare_num++;

        }
        if (strcmp(word, word[i]) != 0)
            printf("0 %d", compare_num);
    }
    if (method == '2'){
        bisearch(0, count, word);
        if(!is_find){
            printf("0 %d", time);
        }
    }
}


