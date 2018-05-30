#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i,j;
    char str[1000];
    scanf("%s", &str);
    for (i = 0; i < strlen(str); ++i)
    {
        if (str[i] == '-')
        {
            if ((str[i-1] >= 'a' && str[i-1] <= 'z') && (str[i+1] >= 'a' && str[i+1] <= 'z'))
            {
                int n = str[i-1] - str[i+1];
                if (n > 0)
                {
                    for (j = 1; j < n; ++j)
                    {
                        printf("%c", str[i-1]-j);
                    }

                }else{
                    n = str[i+1] - str[i-1];
                    for (j = 1; j < n; ++j)
                    {
                        printf("%c", str[i-1] + j);
                    }
                }
            }else if ((str[i-1] >= 'A' && str[i-1] <= 'Z') && (str[i+1] >= 'A' && str[i+1] <= 'Z'))
            {
                int n = str[i-1] - str[i+1];
                if (n > 0)
                {
                    for (j = 1; j < n; ++j)
                    {
                        printf("%c", str[i-1]-j);
                    }

                }else{
                    n = str[i+1] - str[i-1];
                    for (j = 1; j < n; ++j)
                    {
                        printf("%c", str[i-1] + j);
                    }
                }
            }else if ((str[i-1] >= '0' && str[i-1] <= '9') && (str[i+1] >= '0' && str[i+1] <= '9'))
            {
                int n = str[i-1] - str[i+1];
                if (n > 0)
                {
                    for (j = 1; j < n; ++j)
                    {
                        printf("%c", str[i-1]-j);
                    }

                }else{
                    n = str[i+1] - str[i-1];
                    for (j = 1; j < n; ++j)
                    {
                        printf("%c", str[i-1] + j);
                    }
                }
            } else{
                printf("-");
            }
        }else{
            printf("%c", str[i]);
        }
    }
    return 0;
}