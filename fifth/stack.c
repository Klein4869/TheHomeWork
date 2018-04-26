#include <stdio.h>

int main()
{
    int x;
    int stack[1000] = {0};
    int up = 0;
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
        {
            break;
        }
        else if (x == 0)
        {
            if (up == 0)
            {
                printf("error ");
                continue;
            }
            printf("%d ", stack[--up]);
        }
        else if (x == 1)
        {
            int new_x;
            scanf("%d", &new_x);
            stack[up++] = new_x;
        }
    }
}