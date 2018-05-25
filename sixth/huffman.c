#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct wordtree
{
    char word;
    int num;
    struct wordtree *left;
    struct wordtree *right;
};

void qc(struct wordtree **a, int left, int right){
    if (left - right <=0)
    {
        return;
    }
    int i = left;
    int j = right;
    struct wordtree *key = a[0];
    while(i < j){
        while(a[j] == NULL || (i < j && a[j]->num >= key->num))
            j--;
        a[i] = a[j];
        while(a[i] == NULL || (i < j && a[i]->num <= key->num))
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
    num[0] = 1;
    char words1[100];
    int words[100];
    FILE *fp = fopen("/Users/haidongtang/Desktop/in.txt", "r");
    char c;
    while(!feof(fp)){
        c = fgetc(fp);
        num[c]++;
    }
    for (i = 0; i < 1000; ++i)
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
        w[i]->word = words1[i];
        w[i]->left = NULL;
        w[i]->right = NULL;
    }
    qc(w, 0, counter-1);
    for (int i = 0; i < counter; ++i)
    {
        head = malloc(sizeof(struct wordtree));
        head->left = w[0];
        head->right = w[1];
        head->num = w[0]->num + w[1]->num;
        w[0] = head;
        w[1] = NULL;
    }
    free(w);
}