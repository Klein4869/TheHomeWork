#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int a[1001],b[1001];
    int i=0;
    scanf("%d",&a[i++]);
    while(a[i-1] != -1){
        scanf("%d",&a[i++]);
    }
    int num_A = i;
    i = 0;
    scanf("%d",&b[i++]);
    while(b[i-1] != -1){
        scanf("%d",&b[i++]);
    }
    int num_B = i;
    int j;
    for (i = 0; i < num_A; ++i)
    {
        for (j = 0; j < num_B; ++j)
        {
            if (a[i] == b[j])
            {
                break;
            }else if (a[i] != b[j] && j==num_B-1)
            {
                printf("%d ", a[i]);
            }
        }
    }
    printf("\n");
    return 0;
}