#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char s[5000];
    char temp[20]="";
    int x[1002];
    char y[1000];
    int i=0,j=0;
    int a=0,b=0;
    int tmp;
    scanf("%c",&s[i++]);
    while (s[i-1] != '='){
        scanf("%c",&s[i++]);
    }
    i = 0;
    while(s[i] != '='){
        int k;
        if (s[i] >= '0' && s[i]<='9')
        {
            temp[j++] = s[i];
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            x[a++] = atoi(temp);
            for (k = 0; k < j; ++k) {
                temp[k] = '\0';
            }
            j = 0;
            y[b++] = s[i];
        }
        i++;
    }
    x[a] = atoi(temp);
    for (i = 0; i < b; ++i)
    {
        int u = i;
        int t = 1;
        while (x[u] == -1)
        {
            u--;
        }
        while (x[i+t] == -1)
        {
            t++;
        }
        if (y[i] == '*')
        {
            tmp = x[u]*x[i+t];
            x[u] = tmp;
            x[i+t] = -1;
        }
        if (y[i] == '/')
        {
            tmp = x[u]/x[i+t];
            x[u] = tmp;
            x[i+t] = -1;
        }
    }
    for (i = 0; i < b; ++i)
    {
        int u = i;
        int t = 1;
        while (x[u] == -1)
        {
            u--;
        }
        while(x[i+t] == -1){
            t++;
        }
        if (y[i] == '+')
        {
            tmp = x[u] + x[i+t];
            x[u] = tmp;
            x[i+t] = - 1;
        }
        if (y[i] == '-')
        {
            tmp = x[u] - x[i+t];
            x[u] = tmp;
            x[i+t] = - 1;
        }
    }
    for (i = 0; i < b; ++i)
    {
        if (x[i] != -1)
        {
            printf("%d\n", x[i]);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}