#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *fp1;
	FILE *fp2;
	char x[100];
	char y[100];
	scanf("%s",x);
	scanf("%s",y);
	fp1 = fopen("filein.txt","r");
	fp2 = fopen("fileout.txt", "w");
	int flag = 0;
	char tmp[100]="";
	int temp;
	int i;
	while(!feof(fp1)){
		if(flag < strlen(x)){
			char c=fgetc(fp1);
			if (c == EOF)
			{
				fclose(fp1);
				fclose(fp2);
				return 0;
			}
			if (c == x[flag] || c == x[flag] + 32 || c == x[flag] - 32)
			{
				tmp[flag++] = c;
			}
			else if (c != x[flag] || c!= x[flag] + 32 || c == x[flag] - 32)
			{
				flag = 0;
				fprintf(fp2, "%s", tmp);
				temp = strlen(tmp);
				for (i = 0; i < temp; ++i)
				{
					tmp[i] = '\0';
				}
				fprintf(fp2, "%c", c);
			}
			if (flag == strlen(x))
			{
				fprintf(fp2, "%s", y);
				flag = 0;
				temp = strlen(tmp);
				for (i = 0; i < temp; ++i)
				{
					tmp[i] = '\0';
				}
			}
		}

	}
	return 0;
}