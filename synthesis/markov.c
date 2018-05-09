#include <string.h>
#include "stdio.h"
#include "search.cpp"

struct dir
{
    int length;
    char words[10][30];
    char word1[30];
    char word2[30];
};

int count=0;
struct dir markovs[1000001];

int find_word(char tmp){    //确认是否是单词
    if (tmp >= 'a' && tmp <= 'z'){
        return 1;
    }
    if (tmp >= 'A' && tmp <= 'Z'){
        return 1;
    }
    return 0;
}

int duplicate_check(){  //重复检测函数
    int i;
    for (i = 0; i < count-1; ++i) {
        if (!(strcmp(markovs[count-1].word1, markovs[i].word1) || strcmp(markovs[count-1].word2, markovs[i].word2))){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char temp[2000];
    FILE* fp = fopen("article.txt", "r");
    while(!feof(fp)){
        fgets(temp, 2000, fp);
        int i=0;
        int j;
        int k;
        char tmp[30];
        int flag = 0;
        int is_first = 1;
        while(temp[i] != '\0'){
            if (find_word(temp[i])){
                tmp[j++] = temp[i];
            }
            if (temp[i] == ' '){
                tmp[j++] = '\0';
                j = 0;
                if (flag == 0) {
                    strcpy(markovs[count].word1, tmp);
                    flag = 1;
//                    i++;
//                    continue;
                }
                else if (flag == 1){
                    if (!is_first){         //检查是不是第一次遇到第二个
                        markovs[count].length++;
                        strcpy(markovs[count].words[k++], tmp);
                    }
                    strcpy(markovs[count++].word2, tmp);
                    if (!duplicate_check()) {       //检查是否重复
                        strcpy(markovs[count].word1, markovs[count - 1].word2);
                    } else{
                        count--;
                        strcpy(markovs[count].word1, markovs[count].word2);
                    }
                    is_first = 0;
                }
            }
            i++;
        }
    }
    return 0;
}
