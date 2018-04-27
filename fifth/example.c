#include <stdio.h>

int main(){
    FILE *fp = fopen("example.c", "r");
    char x[200];
    while(!feof(fp)){
        fgets(x, 200, fp);
        printf("%s", x);
    }
    return 0;
}