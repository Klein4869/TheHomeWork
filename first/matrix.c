#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    int a[11][11], b[11][11];
    scanf("%d", &n);
    char x;
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    while(1){
        scanf("\n");
        scanf("%c", &x);
        if (x == '#')
        {
            break;
        }else{
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {
                    scanf("%d", &b[i][j]);
                }
            }
            if (x == '+'){
                for (i = 0; i < n; ++i)
                {
                    for (j = 0; j < n; ++j)
                    {
                        a[i][j] += b[i][j];
                    }
                }
            }
            else if (x == '-')
            {
                for (i = 0; i < n; ++i)
                {
                    for (j = 0; j < n; ++j)
                    {
                        a[i][j] -= b[i][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}