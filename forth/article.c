#include "stdio.h"
#include "string.h"

struct words
{
    char content[50];
    int times;
};

struct words word[1000];

void qs(int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    struct words key = word[left];
    while (i < j) {
        while (i < j && strcmp(word[j].content, key.content) >= 0)
            j--;
        word[i] = word[j];
        while (i < j && strcmp(word[i].content, key.content) <= 0)
            i++;
        word[j] = word[i];
    }

    word[i] = key;
    qs(left, j - 1);
    qs(i + 1, right);

}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("article.txt", "r");
    char c;
    struct words tmp;
    int num=0;
    int i;
    while(!feof(fp)){
        c = fgetc(fp);
        int i = 0;
        int isfind = 0;
        while ((c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z'))
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c + 'a' - 'A';
            }
            tmp.content[i++] = c;
            isfind = 1;
            c = fgetc(fp);
        }
        tmp.content[i]='\0';
        if (isfind == 1)
        {
            tmp.times = 1;
            int flag = 0;
            for (i = 0; i < num; ++i)
            {
                if (!strcmp(tmp.content, word[i].content))
                {
                    word[i].times++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                word[num++] = tmp;
            }
        }
    }
    fclose(fp);
    qs(0, num-1);
    for (i = 0; i < num; ++i)
    {
        printf("%s %d\n", word[i].content, word[i].times);
    }
    return 0;
}