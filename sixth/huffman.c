#include "stdio.h"
#include "string.h"

struct word
{
    char word;
    int num;
    int index;
};

void qc(struct word *a, int left, int right){
    if (left - right <=0)
    {
        return;
    }
    int i = left;
    int j = right;
    struct word key = a[0];
    while(i < j){
        while(i < j && a[j].num >= key.num)
            j--;
        a[i] = a[j];
        while(i < j && a[i].num <= key.num)
            i++;
        a[j] = a[i];
    }
    a[i] = key;
    qc(a, left, i-1);
    qc(a, j+1, right);
}

int main(int argc, char const *argv[])
{
    int i,  counter = 0, j = 0;
    int num[1000] = {0};
    struct word words[1000];
    FILE *fp = fopen("/Users/haidongtang/Desktop/in.txt", "r");
    char c;
    while(!feof(fp)){
        c = fgetc(fp);
        num[c]++;
    }
    for (i = 0; i < 1000; ++i){
        words[i].index = -1;
        words[i].num = 0;
    }
    for (i = 0; i < 1000; ++i) {
        if(num[i] != 0){
            words[counter].word = i;
            words[counter++].num = num[i];
        }
    }
    qc(words, 0, counter-1);
    while(j != 1){
        for (i = 0, j = 2; i < counter; ++i)
        {
            if (j == 0)
                break;
            if (words[i].index == -1)
            {
                words[counter].num += words[i].num;
                j--;
                words[i].index = counter;
            }
        }
        counter++;
        qc(words, 0, counter-1);
    }
    counter--;
    printf("helloworld\n");
    return 0;
}