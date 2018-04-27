#include <stdio.h>

struct Brackets
{
    int line;
    char b;
    int is_out;
};

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("/Users/haidongtang/Desktop/数据结构/TheHomeWork/fifth/example1.c", "r");
    char x[200];
    struct Brackets b[200];
    int line = 0;
    int is_inbracket = 0;
    int t = 0;
    while (!feof(fp))
    {
        fgets(x, 200, fp);
        line++;
        int i = 0;
        while (x[i] != '\0')
        {
            if (x[i] == '"')
            {
                if (!is_inbracket)
                {
                    is_inbracket = 1;
                }
                else
                {
                    is_inbracket = 0;
                }
                i++;
                continue;
            }
            if (is_inbracket)
            {
                i++;
                continue;
            }
            if (x[i] == '/' && x[i + 1] == '/')
            {
                break;
            }
            if (x[i] == '{' || x[i] == '}' || x[i] == '(' || x[i] == ')')
            {
                b[t].is_out = 0;
                b[t].b = x[i];
                b[t++].line = line;
                i++;
                continue;
            }
            i++;
        }
    }
    int j, i, k;
    for (j = 0; j < t; ++j)
    {
        printf("%c", b[j].b);
        for (i = j + 1; i < t; ++i)
        {
            if (b[j].is_out)
            {
                break;
            }
            if (b[i].is_out)
            {
                continue;
            }
            if (b[j].b == '(' && b[i].b == ')')
            {
                b[j].is_out = 1;
                b[i].is_out = 1;
                break;
            }
            if (b[j].b == '{' && b[i].b == '}')
            {
                b[j].is_out = 1;
                b[i].is_out = 1;
                break;
            }
        }
    }
    for (k = 0; k < t; ++k)
    {
        if (!b[k].is_out)
        {
            printf("without matching '%c' at line %x\n", b[k].b, b[k].line);
        }
    }
    fclose(fp);
    return 0;
}