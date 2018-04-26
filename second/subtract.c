#include <stdio.h>

void minus(int *a, int *b, int i, int j){
    int max;
    int flag = 0;
    int c[1000]={0};
    if (i >= j)
    {
        max = i;
    }else{
        max = j;
        flag = 1;
    }
    int k;
    for (k = 0; k < max; ++k)
    {
        if (flag == 0)
        {
            if (j-1-k < 0)
            {
                c[k] = c[k] + (a[i - 1 - k] - 0);
            }else{
                c[k] = c[k] + (a[i - 1 - k] - b[j - 1 - k]);
            }
        }else{
            if (i-1-k < 0)
            {
                c[k] = c[k] + (b[j - 1 - k] - 0);
            }else{
                c[k] = c[k] + (b[j - 1 - k] - a[i - 1 - k]);
            }
        }
    }
    int l,flag2;
    for (l = max; l >= 0; --l) {
        if (c[l] != 0) {
            flag2 = l;
            break;
        }
    }

    for (l = 0; l < flag2; l++) {
        if (c[l] < 0){
            c[l] = 10 + c[l];
            c[l+1]--;
        }
    }
    int flag1 = 0;
    if(flag == 1){
        printf("-");
    }
    for (k = flag2; k >= 0; --k)
    {
        if (flag1 == 0)
        {
            if (c[k] == 0)
            {
                continue;
            }
        }
        flag1 = 1;
        printf("%d", c[k]);
    }
    if (flag1 == 0 && c[0] == 0){
        printf("0");
    }
}

int main(int argc, char const *argv[])
{
    int a[1000]={0},b[1000]={0};
    char s;
    int i = 0;
    int j = 0;
    scanf("%c", &s);
    while(s != '\n'){
        a[i++] = s - '0';
        scanf("%c", &s);
    }
    scanf("%c", &s);
    while(s != '\n'){
        b[j++] = s - '0';
        scanf("%c", &s);
    }
    minus(a,b,i,j);
    return 0;
}