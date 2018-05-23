#include "stdio.h"
#include "string.h"

struct treenode
{
    int index;
    int level;
    char name[30];
};

int main(int argc, char const *argv[])
{
    struct treenode t[10];
    int flag = 0;
    int kided_number;
    int counter = 3;
    char file_in_name[] = "in.txt";
    FILE *fp = fopen(file_in_name, "r");
    fscanf(fp, "%d\n", &kided_number);
    while(kided_number--){
        char name1[30],name2[30],name3[30];
        fscanf(fp, "%s %s %s\n", name1, name2, name3);
        if (flag == 0)
        {
            flag = 1;
            strcpy(t[0].name, name1);
            t[0].index = -1;
            t[0].level = 0;
            t[1].index = 0;
            t[1].level = 1;
            strcpy(t[1].name, name2);
            t[2].index = 0;
            t[2].level = 1;
            if (strcmp("NULL", name3))
            {
                strcpy(t[2].name, name3);
            }else{
                counter = 2;
            }
        }
        else
        {
            int i;
            for (i = 0; i < counter; ++i)
            {
                if (!strcmp(name1, t[i].name))
                {
                    t[counter].index = i;
                    t[counter].level = t[i].level+1;
                    strcpy(t[counter++].name, name2);
                    if (strcmp(name3, "NULL"))
                    {
                        t[counter].index = i;
                        t[counter].level = t[i].level+1;
                        strcpy(t[counter++].name, name3);
                    }
                    break;
                }
            }
        }
    }
    int i;
    char name_1[30], name_2[30];
    scanf("%s %s", name_1, name_2);
    int level_1, level_2;
    int index_1, index_2;
    int order=0;
    int flag1 = 0;
    for (i = 0; i < counter; ++i)
    {
        if (!strcmp(name_1, t[i].name))
        {
            index_1 = i;
            level_1 = t[i].level;
            flag1++;
            if (flag1 == 2) {
                break;
            }
        }
        if (!strcmp(name_2, t[i].name))
        {
            index_2 = i;
            level_2 = t[i].level;
            flag1++;
            if (flag1 == 1)
            {
                order = 1;
            }
            if (flag1 == 2) {
                break;
            }
        }
    }
    if (level_1 == level_2) {
        while(index_1 != index_2){
            index_1 = t[index_1].index;
            index_2 = t[index_2].index;
        }
        if (order == 0)
        {
            printf("%s %s %d\n", t[index_1].name, name_1, level_1 - t[index_1].level);
            printf("%s %s %d\n", t[index_1].name, name_2, level_1 - t[index_1].level);
        }
        else{
            printf("%s %s %d\n", t[index_1].name, name_2, level_1 - t[index_1].level);
            printf("%s %s %d\n", t[index_1].name, name_1, level_1 - t[index_1].level);
        }
    }
    else{
        int level = level_1 - level_2;
        if (level > 0)
        {
            printf("%s %s %d\n", name_1, name_2, level);
        }
        else{
            printf("%s %s %d\n", name_2, name_1, -level);
        }
    }
    return 0;
}