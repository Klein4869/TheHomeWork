#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char x[100];
    int head;
};

struct expressions
{
    int x;
    char y;
};

int main(int argc, const char *argv[])
{
    struct stack stack1;
    stack1.head = 0;
    char x[200];
    char y[200];
    int num[200];
    char number[10];
    int number1[100];
    struct expressions e[200];
    int n;
    for (n = 0; n < 200; ++n)
    {
        e[n].x = -200;
        e[n].y = 0;
    }
    gets(x);
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    while (x[i] != '\0')
    {
        if (x[i] == '+' || x[i] == '-')
        {
            if (k > 0)
            {
                number[k] = '\0';
                k = 0;
                number1[l++] = atoi(number);
                e[m++].x = number1[l - 1];
            }
            while (stack1.x[stack1.head] == '+' || stack1.x[stack1.head] == '-' || stack1.x[stack1.head] == '/' ||
                   stack1.x[stack1.head] == '*')
            {
                if (stack1.x[stack1.head] == '(')
                {
                    break;
                }
                if (stack1.head == 0)
                {
                    break;
                }
                y[j++] = stack1.x[stack1.head--];
                e[m++].y = y[j - 1];
            }
            stack1.head++;
            stack1.x[stack1.head] = x[i];
            i++;
            continue;
        }
        if (x[i] == '*' || x[i] == '/')
        {
            if (k > 0)
            {
                number[k] = '\0';
                k = 0;
                number1[l++] = atoi(number);
                e[m++].x = number1[l - 1];
            }
            while (stack1.x[stack1.head] == '/' || stack1.x[stack1.head] == '*')
            {
                if (stack1.x[stack1.head] == '(')
                {
                    break;
                }
                if (stack1.head == 0)
                {
                    break;
                }
                y[j++] = stack1.x[stack1.head--];
                e[m++].y = y[j - 1];
            }
            stack1.head++;
            stack1.x[stack1.head] = x[i];
            i++;
            continue;
        }
        if (x[i] == '(')
        {
            if (k > 0)
            {
                number[k] = '\0';
                k = 0;
                number1[l++] = atoi(number);
                e[m++].x = number1[l - 1];
            }
            stack1.head++;
            stack1.x[stack1.head] = x[i];
            i++;
            continue;
        }
        if (x[i] == ')')
        {
            if (k > 0)
            {
                number[k] = '\0';
                k = 0;
                number1[l++] = atoi(number);
                e[m++].x = number1[l - 1];
            }
            while (stack1.x[stack1.head] != '(')
            {
                y[j++] = stack1.x[stack1.head--];
                e[m++].y = y[j - 1];
            }
            if (stack1.x[stack1.head] == '(')
            {
                stack1.head--;
            }
            i++;
            continue;
        }
        if (x[i] >= '0' && x[i] <= '9')
        {
            number[k++] = x[i];
            y[j++] = x[i++];
        }
        else
            i++;
    }
    if (k != 0)
    {
        number[k] = '\0';
        k = 0;
        number1[l++] = atoi(number);
        e[m++].x = number1[l - 1];
    }
    while (stack1.head != 0)
    {
        y[j++] = stack1.x[stack1.head--];
        e[m++].y = y[j - 1];
    }
    // printf("%s\n", y);
    // int i1;
    // for (i1 = 0; i1 < m; ++i1)
    // {
    //     if (e[i1].x == -200)
    //     {
    //         printf("%c", e[i1].y);
    //     }
    //     if (e[i1].y == 0)
    //     {
    //         printf("%d", e[i1].x);
    //     }
    // }
    int j1;
    for (j1 = 0; j1 < m; ++j1)
    {
        if (e[j1].y != 0)
        {
            int k1 = j1 - 1;
            while (e[k1].x == -200)
            {
                k1--;
            }
            int k2 = k1 - 1;
            while (e[k2].x == -200)
            {
                k2--;
            }
            if (e[j1].y == '+')
            {
                e[k2].x = e[k1].x + e[k2].x;
                e[k1].x = -200;
                e[k1].y = 0;
            }
            if (e[j1].y == '-')
            {
                e[k2].x = e[k2].x - e[k1].x;
                e[k1].x = -200;
                e[k1].y = 0;
            }
            if (e[j1].y == '*')
            {
                e[k2].x = e[k1].x * e[k2].x;
                e[k1].x = -200;
                e[k1].y = 0;
            }
            if (e[j1].y == '/')
            {
                e[k2].x = e[k2].x / e[k1].x;
                e[k1].x = -200;
                e[k1].y = 0;
            }
            e[j1].x = -200;
            e[j1].y = 0;
        }
    }
    // printf("\n");
    int l1;
    //    for (l1 = 0; l1 < 200; ++l1) {
    //        if (e[l1].x != -200){
    //            printf("%d", e[l1].x);
    //        }
    //    }
    printf("%d\n", e[0].x);
    return 0;
}