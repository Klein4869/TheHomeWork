#include <stdio.h>
#include <string.h>

struct user{
    char name[15];
    char tel[15];
};

int main(int argc, char const *argv[])
{
    struct user u[51];
    char n[51][15];
    int x;
    int i,j;
    int people[51]={0};
    scanf("%d",&x);
    for (i = 0; i < x; ++i) {
        char name[15] = "";
        char tel[15] = "";
        scanf("%s %s", name, tel);
        name[10] = '\0';
        tel[10] = '\0';

        strcpy(u[i].name, name);
        strcpy(u[i].tel, tel);

        strcpy(n[i],name);
    }
    char t[15];
    for(i=0; i<x-1; i++){
        int k=i;
        for(j=i+1; j<x; j++)
            if(strcmp(n[j],n[k])<0) k=j;
        strcpy(t,n[i]);
        strcpy(n[i],n[k]);
        strcpy(n[k],t);
    }
    for (i = 0; i < x; ++i) {
        for (j = 0; j < x; ++j) {
            if (!strcmp(u[j].name,n[i])){
                printf("%12s%12s\n",u[j].name,u[j].tel);
                break;
            }
        }
    }
    return 0;
}