#include <iostream>
#include "stdio.h"

int is_find = 0;

struct treenode
{
    int depth;
    struct treenode *left;
    struct treenode *right;
    int value;
};

void insert(struct treenode *node, int temp, int depth){
    if (node->depth == 0)
    {
        node->value = temp;
        return;
    }
    node->value = temp;
    node->depth = depth;
    node->left = NULL;
    node->right = NULL;
}

void find(struct treenode *node, int temp){
    if (is_find == 1)
    {
        return;
    }

    if (node->value == 0)
    {
        insert(node, temp, 0);
        return;
    }
    if (temp >= node->value)
    {
        if (node->right == NULL)
        {
            struct treenode n;
            node->right = &n;
            insert(node->right, temp, node->depth+1);
            is_find = 1;
            return;
        }else{
            find(node->right, temp);
        }
    }else{
        if (node->left == NULL)
        {
            struct treenode n;
            node->left = &n;
            insert(node->left, temp, node->depth+1);
            is_find = 1;
            return;
        }else{
            find(node->left, temp);
        }
    }
}


int main(int argc, char const *argv[])
{
    struct treenode headnode;
    struct treenode *h;
    h = &headnode;
    headnode.value = 0;
    headnode.depth = 0;
    headnode.left = NULL;
    headnode.right = NULL;
    int num;
    scanf("%d", &num);
    while(num--){
        int temp;
        scanf("%d", &temp);
        // if (max_depth == 0)
        // {
        //     max_depth++;
        //     tnode[0][0].value = temp;
        //     tnode[0][0].depth = max_depth;
        //     count[0]++;
        //     continue;
        // }
        is_find = 0;
        // struct treenode tmp;
        // tmp.value = temp;
        find(h, temp);
    }
    return 0;
}
