#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen("fcopy.in", "r");
	fp2 = fopen("fcopy.out", "w");
	if (fp1 != NULL && fp2 != NULL)
	{
		char c;
		c = fgetc(fp1);
		if (c == '\t')
		{
			c = ' ';
		}
		while(c != EOF){
			char c1 = c;
			c = fgetc(fp1);
			if (c == '\t')
			{
				c = ' ';
			}			
			if (c == c1 && c1 == ' ')
			{
				continue;
			}else
			{
				fputc(c1, fp2);
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}