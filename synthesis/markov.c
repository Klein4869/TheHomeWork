#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

char input[10000000];
char *word[5000000];
int wordNum = 0;
int k = 2;
int next[5000000];
int bin[13131313];
char *wordBin[13131313];
int N[13131313];

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

unsigned long long hash(char *str)
{
	int a = 10971;
	int n;
	unsigned long long h = 0;
	char *p = str;
	for (n = k; n > 0; ++p)
	{
		h = h * a + *p;
		if (*p == '\0')
			--n;
	}
	return (h % 13131313);
}

int wordCmp(char *p, char *q)
{
	int n;
	for (n = k; *p == *q; ++p, ++q)
	{
		if (*p == '\0' && (--n) == 0)
			return 0;
	}
	return *p - *q;
}

int wordCmp1(int i, int j)
{
	if (!strcmp(word[i], word[j]) && !strcmp(word[i + 1], word[j + 1]))
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
	long long i, j;
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
		while (wordBin[j] != NULL && wordCmp(word[i], wordBin[j]) != 0)
			j++;
		next[i] = bin[j];
		int temp = i;
		while (next[temp] != -1)
			temp = next[temp];
		next[temp] = i;
		next[i] = -1;
		if (bin[j] == -1)
		{
			bin[j] = temp;
			wordBin[j] = word[i];
		}
		N[j]++;
	}

	int wordsleft, n, m;
	char *phrase, *p;
	phrase = input;

	FILE *fp1 = fopen("markov.txt", "w");

	fprintf(fp1, "%s %s ", word[0], word[1]);

	int max = 100, num = 0, shit, num1 = 0;
	scanf("%d", &max);
	int chongtu = 0;

	for (wordsleft = max; wordsleft > 0; --wordsleft)
	{
		m = hash(phrase);
		while (wordCmp(phrase, wordBin[m]) != 0)
			m++;
		n = N[m];
		// m = hash(phrase);
		// for (j = bin[hash(phrase)]; j >= 0; j = next[j])
		// {
		// 	if (wordCmp(phrase, word[j]) == 0)
		// 		n++;
		// }
		if (n == 1)
			n = 0;
		else
			n = (int)(rrand() * n);
		for (j = bin[m]; j >= 0; j = next[j])
		{
			if (n-- == 0)
			{
				p = word[j];
				break;
			}
		}
		phrase = skip(p, 1);
		if (strlen(skip(phrase, k - 1)) == 0)
			break;
		fwrite(skip(phrase, k - 1), strlen(skip(phrase, k - 1)), 1, fp1);
		fwrite(" ", 1, 1, fp1);
		// fprintf(fp1, "%s ", word[j+2]);
	}
	//fprintf(fp1, "%d ", num);
	return 0;
}
