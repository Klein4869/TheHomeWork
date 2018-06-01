#include <string.h>
#include "stdio.h"

int is_find = 0;
int time = 0;

char words[3600][30];

int bisearch(int first, int last, char *b){
    if(first > last)
        return -1;
    int mid = first + (last - first)/2;
    time++;
    if(strcmp(words[mid], b) > 0)
        return bisearch(first, mid-1, b);
    else if(strcmp(words[mid], b) < 0)
        return bisearch(mid+1, last, b);
    else
        return mid;
}

int main() {
    int count = 0, i, compare_num = 0;
    int first[26];
    int last[26];
    FILE *fp = fopen("/Users/haidongtang/ctest/cmake-build-debug/dictionary3500.txt", "r");
    char temp = '0';
    while (!feof(fp)) {
        fscanf(fp, "%s", words[count++]);
        if (words[count - 1] != temp){
            first[(int)(words[count-1] - 'a')] = count - 1;
            last[temp - 'a'] = count - 2;
        }
        temp = words[count - 1];
    }
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
        int ans = bisearch(0, count, word);
        if(ans == -1){
            printf("0 %d", time);
        } else{
            printf("1 %d", time);
        }
    }
    if (method == '3'){
        
    }
}



