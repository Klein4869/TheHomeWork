#include "string.h"
#include "stdio.h"
#include "stdlib.h"

char input[5000000];
char *word[100000];
int wordNum = 0;
int k = 2;
int next[100000];
int bin[50000];

unsigned int hash(char *str)
{
    int n;
    unsigned int h = 0;
    char *p = str;
    for (n = k; n > 0; ++p)
    {
        h = 31 * h + *p;

        if (*p == '\0')
        {
            --n;
        }
    }
    return h % 50000;
}

int wordCmp(char *p, char *q)
{
    int i;

    for (i = k; *p == *q; p++, q++)
        if (*p == '\0' && (--i) == 0)
            return 0;

    return *p - *q;
}

char *skip(char *p, int n)
{
    for (; n > 0; p++)
        if (*p == '\0')
            --n;
    return p;
}

int main(int argc, char const *argv[])
{
    int i, j;
    word[0] = input;

    FILE *fp = fopen("article.txt", "r");

    while (!feof(fp))
    {
        fscanf(fp, "%s", word[wordNum]);
        word[wordNum + 1] = word[wordNum] + strlen(word[wordNum]) + 1;
        wordNum++;
    }
    for (i = 0; i < 50000; i++)
        bin[i] = -1;
    for (i = 0; i < wordNum - k; i++)
    {
        j = hash(word[i]);
        next[i] = bin[j];
        bin[j] = i;
    }

    int wordsleft;
    int psofar;
    char *phrase, *p;
    phrase = input;

    FILE *fp1 = fopen("markov.txt", "a+");

    fprintf(fp1, "%s %s ", skip(phrase, 0), skip(phrase, 1));

    for (wordsleft = 1000000; wordsleft > 0; --wordsleft)
    {
        psofar = 0;

        for (j = bin[hash(phrase)]; j >= 0; j = next[j])
        {

            if (wordCmp(phrase, word[j]) == 0 && rand() % ++psofar == 0)
            {
                p = word[j];
            }
            phrase = skip(p, 1);

            if (strlen(skip(phrase, k - 1)) == 0)
            {
                break;
            }
            fprintf(fp1, "%s ", skip(phrase, k - 1));
        }
    }

    return 0;
}
