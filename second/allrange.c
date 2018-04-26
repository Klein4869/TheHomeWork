#include <stdio.h>

void allrange(int *a, int *b, int x, int y){
    int i,j;
    for (i = 0; i < x; ++i)
    {
        if (b[i+1] == 1)
        {
            continue;
        }
        a[y-1] = i+1;
        b[i+1] = 1;
        if (y == x)
        {
            for (j = 0; j < x; ++j)
            {
                printf("%d ", a[j]);
            }
            printf("\n");
            a[y-1]=0;
            b[i+1]=0;
            return;
        }
        allrange(a, b, x, y+1);
        a[y-1] = 0;
        b[i+1] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int x;
    int a[11]={0};
    int b[11]={0};
    scanf("%d",&x);
    int i;
    a[0] = 1;
    allrange(a,b,x,1);
    return 0;
}