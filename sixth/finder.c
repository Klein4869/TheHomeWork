#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct family_tree {
    char name[30];
    int depth;
    int count;
    struct family_tree *left;
    struct family_tree *right;
};

char name[5][30];

int counter=0;
int is_find = 0;
int max;
int flag = 1;
struct family_tree f1, f2;
char former_name1[30], former_name2[30];
int former_depth1, former_depth2;

void search_former(struct family_tree *h, char temp[], int x){
    if (is_find == 1){
        return;
    }
    if (h->left != NULL) {
        if (!strcmp(h->left->name, temp)) {
            if (x == 1) {
                strcpy(former_name1, h->name);
                former_depth1 = h->depth;
            }
            if (x == 2) {
                strcpy(former_name2, h->name);
                former_depth2 = h->depth;
            }
            is_find = 1;
            return;
        }
    }
    if (h->right != NULL){
        if (!strcmp(h->right->name, temp)){
            if (x == 1) {
                strcpy(former_name1, h->name);
            }
            if (x == 2) {
                strcpy(former_name2, h->name);
            }
            is_find = 1;
            return;
        }
    }
    if (h->left != NULL){
        search_former(h->left, temp, x);
    }
    if (h->right != NULL){
        search_former(h->right, temp, x);
    }
}

void search(struct family_tree *h, char temp1[], char temp2[], char former_name[]) {
    if (!strcmp(h->name, temp1)){
        strcpy(former_name1, former_name);
        strcpy(f1.name, h->name);
        f1.depth = h->depth;
        f1.count = h->count;
    }
    if (!strcmp(h->name, temp2)){
        strcpy(former_name2, former_name);
        strcpy(f2.name, h->name);
        f2.depth = h->depth;
        f2.count = h->count;
    }
    if (h->left != NULL)
        search(h->left, temp1, temp2, h->name);
    if (h->right != NULL)
        search(h->right, temp1, temp2, h->name);
}

void find(struct family_tree *node, char temp[], struct family_tree *f) {
    if (!strcmp(node->name, "NULL")) {
        strcpy(node->name, f->name);
        node->count = counter++;
        node->left = f->left;
        if (node->left != NULL)
            node->left->depth = node->depth+1;
        node->right = f->right;
        if (node->right != NULL)
            node->right->depth = node->depth+1;
        return;
    }
    if (is_find == 1) {
        return;
    }
    if (!strcmp(node->name, temp)) {
        is_find = 1;
        strcpy(node->name, f->name);
        node->count = counter++;
        node->left = f->left;
        if (node->left != NULL)
            node->left->depth = node->depth+1;
        node->right = f->right;
        if (node->right != NULL)
            node->right->depth = node->depth+1;
        return;
    } else {
        if (node->left != NULL)
            find(node->left, temp, f);
        if (node->right != NULL)
            find(node->right, temp, f);
    }
    if (is_find == 1) {
        return;
    }
}

int main() {
    char file_in_name[] = "in.txt";
    FILE *fp = fopen(file_in_name, "r");
    int kided_number;
    int flag_1 = 0;
    fscanf(fp, "%d\n", &kided_number);
    int total = kided_number;
    struct family_tree *h = (struct family_tree *) malloc(sizeof(struct family_tree));
    strcpy(h->name, "NULL");
    h->depth = 0;
    //创建树
    while (kided_number--) {
        int is_first = 1;
        char temp[200];
        char senpai[30];
        fgets(temp, 200, fp);
        struct family_tree *f = (struct family_tree *) malloc(sizeof(struct family_tree));
        int i = 0;
        int j = 0;
        int k = 0;
        while (temp[i] != '\0') {
            if (temp[i] == ' ') {
                name[k++][j] = '\0';
                j = 0;
                i++;
                continue;
            }
            name[k][j++] = temp[i];
            i++;
        }
        int l;
        flag_1 = 1;
        for (l = 0; l < j; ++l) {
            if (name[k][l] == '\r' || name[k][l] == '\n' || name[k][l] == '\0') {
                name[k++][l] = '\0';
                flag_1 = 0;
                break;
            }
        }
        if (flag_1 == 1) {
            k++;
        }
        //        //考虑家族中只有一人情况
        //        if (flag == 1){
        //            strcpy(head.name, name[k-1]);
        //            head.depth = 0;
        //            flag = 0;
        //        }
        //        //
        max = k;
        strcpy(f->name, name[0]);
        struct family_tree *f_left = (struct family_tree *) malloc(sizeof(struct family_tree));
        struct family_tree *f_right = (struct family_tree *) malloc(sizeof(struct family_tree));
        if (max == 3) {
            if (!strcmp("NULL", name[2])) {
                f->left = f_left;
                f->left->count = counter++;
                f->right = NULL;
                strcpy(f_left->name, name[1]);
            } else {
                f->left = f_left;
                f->right = f_right;
                f->left->count = counter++;
                f->right->count = counter++;
                strcpy(f_left->name, name[1]);
                strcpy(f_right->name, name[2]);
            }
        }
        if (max == 1) {
            f->left = NULL;
            f->right = NULL;
        }
        is_find = 0;
        find(h, name[0], f);
        int x = 2;
    }
    fclose(fp);
    //
    //搜索人名，并输出
    char name1[30];
    char name2[30];
    scanf("%s %s", name1, name2);
    search(h ,name1, name2, " ");
    if(f1.depth == f2.depth){
        if (!strcmp(former_name1, former_name2)){
            printf("%s %s 1\n", former_name1, name1);
            printf("%s %s 1\n", former_name1, name2);
            return 0;
        }
        while (strcmp(former_name1, former_name2)){
            is_find = 0;
            search_former(h, former_name1, 1);
            is_find = 0;
            search_former(h, former_name2, 2);
        }
        if (f1.count < f2.count) {
            printf("%s %s %d\n", former_name1, f1.name, f1.depth - former_depth1);
            printf("%s %s %d\n", former_name1, f2.name, f2.depth - former_depth1);
        } else{
            printf("%s %s %d\n", former_name1, f2.name, f2.depth - former_depth1);
            printf("%s %s %d\n", former_name1, f1.name, f1.depth - former_depth1);
        }
    }

    if (f1.depth != f2.depth) {

        if (f1.depth > f2.depth) {
            printf("%s %s %d\n", f1.name, f2.name, f1.depth-f2.depth);
        }

        else
        {
            printf("%s %s %d\n", f2.name, f1.name, f2.depth-f1.depth);
        }


    }

    return 0;
}