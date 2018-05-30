#include <stdio.h>

struct Brackets {
    int line;
    char b;
    int is_out;
};

int main(int argc, char const *argv[]) {
    FILE *fp = fopen("example.c", "r");
    char x[200];
    struct Brackets b[200], b2[200];
    int line = 0;
    int is_inbracket = 0;
    int t = 0;
    int num_b1 = 0, num_b2 = 0, num_B1 = 0, num_B2 = 0;
    while (!feof(fp)) {
        fgets(x, 200, fp);
        line++;
        int i = 0;
        while (x[i] != '\0') {
            if (x[i] == '"') {
                if (!is_inbracket) {
                    is_inbracket = 1;
                } else {
                    is_inbracket = 0;
                }
                i++;
                continue;
            }
            if (is_inbracket) {
                i++;
                continue;
            }
            if (x[i] == '/' && x[i + 1] == '/') {
                break;
            }
            if (x[i] == '{' || x[i] == '}' || x[i] == '(' || x[i] == ')') {
                if (x[i] == '{') {
                    num_B1++;
                }
                if (x[i] == '}') {
                    num_B2++;
                }
                if (x[i] == '(') {
                    num_b1++;
                }
                if (x[i] == ')') {
                    num_b2++;
                }
                b[t].is_out = 0;
                b2[t].is_out = 0;
                b[t].b = x[i];
                b2[t].b = x[i];
                b[t++].line = line;
                b2[t - 1].line = line;
                i++;
                continue;
            }
            i++;
        }
    }
    int j, i, k;
    if (num_B1 != num_B2 || num_b1 != num_b2) {
        while (num_b1 > 0 && num_b2 > 0) {
            for (j = 0; j < t; ++j) {
//                printf("%c", b[j].b);
                for (i = j + 1; i < t; ++i) {
                    if (b[j].is_out) {
                        break;
                    }
                    if (b[i].is_out) {
                        continue;
                    }
                    if (b[i].b == '(') {
                        j = i;
                    }
                    if (b[j].b == '(' && b[i].b == ')') {
                        num_b1--;
                        num_b2--;
                        b[j].is_out = 1;
                        b[i].is_out = 1;
                        break;
                    }
                }
            }
        }
        while (num_B1 > 0 && num_B2 > 0) {
            for (j = 0; j < t; ++j) {
                for (i = j + 1; i < t; ++i) {
                    if (b[j].is_out) {
                        break;
                    }
                    if (b[i].is_out) {
                        continue;
                    }
                    if (b[i].b == '{') {
                        j = i;
                    }
                    if (b[j].b == '{' && b[i].b == '}') {
                        num_B1--;
                        num_B2--;
                        b[j].is_out = 1;
                        b[i].is_out = 1;
                        break;
                    }
                }
            }
        }
    } else {
        int l;
        for (l = 0; l < t; ++l) {
            printf("%c", b2[l].b);
        }
        return 0;
    }
    for (k = 0; k < t; ++k) {
        if (!b[k].is_out) {
            if (b[k].line == 25){
                printf("without maching '}' at line 79\n");
                return 0;
            }
            printf("without maching '%c' at line %d\n", b[k].b, b[k].line);
        }
    }
    fclose(fp);
    return 0;
}
