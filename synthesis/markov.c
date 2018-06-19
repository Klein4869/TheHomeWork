#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

char input[10000000];
char *word[5000000];
int wordNum = 0;
int k = 2;
int next[5000000];
int bin[1500009];
int N[1500009] = { 0 };

double seed = 997;

double rrand()
{
	double lambda = 3125.0;
	double m = 34359738337.0;
	double r;
	seed = fmod(lambda * seed, m); //要包含头文件#include <math.h>
	r = seed / m;
	return r;
}

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
	return h % 1500009;
}

int wordCmp(int i, int j)
{
	int l;
	if(!strcmp(word[i], word[j]) && !strcmp(word[i+1], word[j+1]))
		return 0;
	return -1;
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
	memset(bin, -1, sizeof(bin));
	for (i = 0; i <= wordNum - k; i++)
	{
		j = hash(word[i]);
		next[i] = bin[j];
		int temp = i;
		while (next[temp] != -1)
			temp = next[temp];
		next[temp] = i;
		next[i] = -1;
		if (bin[j] == -1)
			bin[j] = temp;
	}

	int wordsleft, n;
	char *phrase, *p;
	phrase = input;

	FILE *fp1 = fopen("markov.txt", "w");

	fprintf(fp1, "%s %s ", word[0], word[1]);

	int max = 100;
	scanf("%d", &max);
	int phrase_index = 0;

	for (wordsleft = max; wordsleft > 0; --wordsleft)
	{
		n = 0;
		for (j = bin[hash(phrase)]; j >= 0; j = next[j]) {
			if (wordCmp(phrase_index, j) == 0)
				n++;
		}
		if (n == 1) n = 0;
		else n = (int)(rrand() * n);
		for (j = bin[hash(phrase)]; j >= 0; j = next[j]) {
			if (wordCmp(phrase_index, j) == 0 && n-- == 0)
				break;
		}
		phrase = word[j+1];
		phrase_index = j+1;
		if (strlen(word[j+2]) == 0)
			break;
		fprintf(fp1, "%s ", word[j+2]);
	}
	return 0;
}
