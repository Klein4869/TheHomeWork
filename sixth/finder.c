#include <malloc.h>
#include "stdio.h"
#include "string.h"

struct family_tree {
    char name[30];
    int depth;
    family_tree *left;
    family_tree *right;
};

int is_find = 0;

void insert(struct family_tree *node, char temp[]) {

}

int find(struct family_tree *node, char temp[]) {
    if (is_find == 1) {
        return 1;
    }

    if (!strcmp(node->name, head.name))

}

int main() {
    char file_in_name[] = "in.txt";
    FILE *fp = fopen(file_in_name, "r");
    int kided_number;
    fscanf(fp, "%d", &kided_number);
    int total = kided_number;
    family_tree head;
    family_tree *h;
    h = &head;
    while (kided_number--) {
        char name[30];
        char temp[200];
        fgets(temp, 200, fp);
        family_tree *f = (family_tree *)malloc(sizeof(family_tree));
        int i = 0;
        int j = 0;
        int flag = 1;
        while (temp[i] != '\0') {
            if (temp[i] == ' ') {
                name[j] = '\0';
                j = 0;
                i++;
                //第一个人特殊处理
                if (flag == 1) {
                    strcpy(head.name, name);
                    head.depth = 0;
                    flag = 0;
                }
                //
                //不是第一个人的情况
                strcpy(f->name, name);
                //
                if (find(h, name));
                    continue;
            }
            name[j++] = temp[i];
            i++;
        }
        name[j] = '\0';
        //考虑家族中只有一人情况
        if (flag == 1){
            strcpy(head.name, name);
            head.depth = 0;
            flag = 0;
        }
        //
        if (find())
    }
    return 0;
}