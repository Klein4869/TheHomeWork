#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct family_tree
{
    char name[30];
    int depth;
    family_tree *left;
    family_tree *right;
};

char name[5][30];

int is_find = 0;
int max;
int flag = 1;

void insert(struct family_tree *node, char temp[])
{
}

int find(struct family_tree *node, char temp[], struct family_tree *f)
{
    if (node == NULL)
    {
        node = f;
        return 1;
    }
    if (is_find == 1)
    {
        return 1;
    }
    if (!strcmp(node->name, temp))
    {
        is_find = 1;
        node = f;
        return 1;
    }
    else
    {
        find(node->left, temp, f);
        find(node->right, temp, f);
    }
    if (is_find == 1)
    {
        return 1;
    }
}

int main()
{
    char file_in_name[] = "in.txt";
    FILE *fp = fopen(file_in_name, "r");
    int kided_number;
    fscanf(fp, "%d", &kided_number);
    int total = kided_number;
    family_tree head;
    family_tree *h;
    h = &head;
    while (kided_number--)
    {
        int is_first = 1;
        char temp[200];
        char senpai[30];
        fgets(temp, 200, fp);
        family_tree *f = (family_tree *)malloc(sizeof(family_tree));
        int i = 0;
        int j = 0;
        int k = 0;
        while (temp[i] != '\0')
        {
            if (temp[i] == ' ')
            {
                name[k++][j] = '\0';
                j = 0;
                i++;
                continue;
            }
            name[k][j++] = temp[i];
            i++;
        }
        name[k++][j] = '\0';
        //        //考虑家族中只有一人情况
        //        if (flag == 1){
        //            strcpy(head.name, name[k-1]);
        //            head.depth = 0;
        //            flag = 0;
        //        }
        //        //
        max = k;
        struct family_tree *f_left = (family_tree *)malloc(sizeof(family_tree));
        struct family_tree *f_right = (family_tree *)malloc(sizeof(family_tree));
        if (max == 3)
        {
            if (!strcmp("NULL", name[2]))
            {
                f->left = f_left;
                f->right = NULL;
                strcpy(f_left->name, name[1]);
            }
            f->left = f_left;
            f->right = f_right;
            strcpy(f_left->name, name[1]);
            strcpy(f_right->name, name[2]);
        }
        if (max == 1)
        {
            f->left = NULL;
            f->right = NULL;
        }
        if (find(h, name[0], f))
        {
        }
        getchar();
    }
    fclose(fp);
    return 0;
}