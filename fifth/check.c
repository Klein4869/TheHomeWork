#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("example.c", "r");
    char x;
    char ans[200] = {0};
    int bracket_before = 0, bracket_after = 0;
    int Lbracket_before = 0, Lbracket_after = 0;
    int up = 0;
    x = fgetc(fp);
    while (!feof(fp))
    {
        if (x == '(')
        {
            ++bracket_before;
            ans[up++] = '(';
        }
        if (x == ')')
        {
            ++bracket_after;
            ans[up++] = ')';
        }
        if (x == '{')
        {
            ++Lbracket_before;
            ans[up++] = '{';
        }
        if (x == '}')
        {
            ++Lbracket_after;
            ans[up++] = '}';
        }
        x = fgetc(fp);
    }
    if (bracket_before != bracket_after || Lbracket_before != Lbracket_after)
    {
    }
    else
    {
    }
    fclose(fp);
    return 0;
}