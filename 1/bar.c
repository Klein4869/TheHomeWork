#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char str[]="1";
    int a[27]={0};
    int i, t;
    int Max = 0;
    while(scanf("%s", str) != EOF){
        for (i = 0; i < strlen(str); ++i)
        {
            t = str[i] - 'a';
            if (t > 25 || t < 0)
            {
                continue;
            }
            a[t]++;
            if (a[t] > Max)
            {
                Max = a[t];
            }
        }
    }
    while(Max > 0){
        for (i = 0; i < 26; ++i)
        {
            if (a[i] >= Max)
            {
                printf("*");
            } else{
                printf(" ");
            }
        }
        printf("\n");
        Max--;
    }
    printf("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}