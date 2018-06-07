#include <string.h>
#include "stdio.h"

int is_find = 0;
int time = 0;

char words[3600][30];

struct hash_table{
    int next;
    char word[30];
}hash_table1[100000];

/* compute hash value for string */

#define NHASH  3001

#define MULT  37

unsigned int hash(char *str)
{
    unsigned int h=0;
    char *p;
    for(p=str; *p!='\0'; p++)
    h = MULT*h + *p;
    return h % NHASH;
}

void create_hash(char word[30]){
    int hash_code = hash(word);
    int temp = 100000 - 1;
    if(!strcmp(hash_table1[hash_code].word, "0")){
        strcpy(hash_table1[hash_code].word, word);
    }else{
        while(strcmp(hash_table1[temp].word, "0")){
            temp--;
        }
        while (hash_table1[hash_code].next != 0) {
            hash_code = hash_table1[hash_code].next;
        }
        hash_table1[hash_code].next = temp;
        strcpy(hash_table1[temp].word, word);
    }
}


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
    for (i = 0; i < 100000; ++i){
        strcpy(hash_table1[i].word, "0");
        hash_table1[i].next = 0;
    }
    int first[26];
    int last[26];
    FILE *fp = fopen("dictionary3000.txt", "r");
    char temp = '0';
    while (!feof(fp)) {
        fscanf(fp, "%s", words[count++]);
        create_hash(words[count-1]);
        if (words[count - 1][0] != temp){
            first[words[count-1][0] - 'a'] = count - 1;
            last[temp - 'a'] = count - 2;
        }
        temp = words[count - 1][0];
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
            compare_num++;
            if (strcmp(words[i], word) >= 0) {
                break;
            }
        }
        if (strcmp(word, words[i]) != 0)
            printf("0 %d\n", compare_num);
        else
            printf("1 %d\n", compare_num);
    }
    if (method == '2'){
        int ans = bisearch(0, count-1, word);
        if(ans == -1){
            printf("0 %d\n", time);
        } else{
            printf("1 %d\n", time);
        }
    }
    if (method == '3'){
        int ans = bisearch(first[word[0] - 'a'], last[word[0] - 'a'], word);
        if(ans == -1){
            printf("0 %d\n", time);
        } else{
            printf("1 %d\n", time);
        }
    }
    if (method == '4'){
        int word_hash = hash(word);
        while(strcmp(hash_table1[word_hash].word, "0")){
            time++;
            if (!strcmp(word, hash_table1[word_hash].word))
            {
                printf("1 %d\n", time);
                break;
            }
            if (strcmp(word, hash_table1[word_hash].word) < 0)
            {
                printf("0 %d\n", time);
                break;
            }
            word_hash = hash_table1[word_hash].next;
            if (word_hash == 0) {
                printf("0 %d\n", time);
                break;
            }
        }
    }
}
