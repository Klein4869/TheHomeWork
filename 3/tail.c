#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char ans[1000][1000];

int main(int argc, char const *argv[])
{
	char filename[20];
	int n = 10;
	n = atoi(argv[1]);
	n = -n;
	strcpy(filename, argv[2]);
	FILE *fp1;
	fp1 = fopen(filename, "r");
	int j=0;
	while(!feof(fp1)){
		fgets(ans[j++], 1000, fp1);
		//printf("%s", ans[j-1]);
	}
	int last = j-1;
	int i;

	for (i = last - n; i < last; ++i)
	{
		printf("%s", ans[i]);
	}
	//printf("%d\n", last);
	return 0;
}