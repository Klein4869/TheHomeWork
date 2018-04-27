#include <stdio.h>
int main(int argc, char const *argv[])
{
    FILE *fp = fopen("example.c", "r");
    char x;
    char ans[2000] = {0};
    char content[2000] = {0};
    int bracket_before = 0, bracket_after = 0;
    int Lbracket_before = 0, Lbracket_after = 0;
    int up = 0;
    int i = 0;
    x = fgetc(fp);
    int line = 0;
    int last_line1, last_line2, last_line3, last_line4;
    while (!feof(fp))
    {
        if (x == '\n')
        {
            line++;
        }
        if (x == '(')
        {
            ++bracket_before;
            ans[up++] = '(';
            last_line1 = line;
        }
        if (x == ')')
        {
            ++bracket_after;
            ans[up++] = ')';
            last_line2 = line;
        }
        if (x == '{')
        {
            ++Lbracket_before;
            ans[up++] = '{';
            last_line3 = line;
        }
        if (x == '}')
        {
            ++Lbracket_after;
            ans[up++] = '}';
            last_line4 = line;
        }
        x = fgetc(fp);
        content[i++] = x;
    }
    if (bracket_before != bracket_after || Lbracket_before != Lbracket_after)
    {
        int last_line_tmp;
        char y;
        if (bracket_before > bracket_after)
        {
            last_line_tmp = last_line1;
            y = '(';
        }
        else if (bracket_before < bracket_after)
        {
            last_line_tmp = last_line2;
            y = ')';
        }
        else if (Lbracket_before > Lbracket_after)
        {
            last_line_tmp = last_line3;
            y = '{';
        }
        else if (Lbracket_before > Lbracket_after)
        {
            last_line_tmp = last_line4;
            y = '}';
        }
        printf("without matching '%c' at line %d\n", y, last_line_tmp);
    }
    else
    {
        printf("%s", ans);
    }
    fclose(fp);
    return 0;
}