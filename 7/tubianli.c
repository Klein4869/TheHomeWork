#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int is_find;
    int value;
    struct node *next;
}node;

typedef struct graph {
    node *node_list[100];
    int node_num;
    int side_num;
}graph;

void showAdjacentList(graph *graph1) {
    int i;
    node *edgeNode;
    for (i = 0; i <= graph1->node_num; i++) {
        printf("顶点%d", i);
        edgeNode = graph1->node_list[i];
        while (edgeNode) {
            printf("->%d", edgeNode->value);
            edgeNode = edgeNode->next;
        }
        printf("\n");
    }
}

void bfs(){
    
}

void dfs(graph graph1, int i){
    if(graph1.node_list[i]->is_find == 0){
        printf("%d",graph1.node_list[i]->value);
    }else{
        return;
    }
    node *n_temp = graph1.node_list[i]->next;
    while(n_temp){
        dfs(graph1, n_temp->value);
        n_temp = n_temp->next;
    }
}

int main() {
    graph graph1;
    int i, node_num, side_num;
    for (i = 0; i < graph1.node_num; ++i) {
        graph1.node_list[i] = NULL;
        graph1.node_list[i]->next = NULL;
    }
    node *node1;
    scanf("%d%d", &node_num, &side_num);
    graph1.node_num = node_num;
    for (i = 0; i < side_num; ++i) {
        int start, end;
        scanf("%d%d", &start, &end);
        node1 = (node*)malloc(sizeof(node));
        node1->value = end;
        node1->next = graph1.node_list[start];
        graph1.node_list[start] = node1;
        graph1.node_list[start]->is_find = 0;
        node1 = (node*)malloc(sizeof(node));
        node1->value = start;
        node1->next = graph1.node_list[end];
        graph1.node_list[end] = node1;
        graph1.node_list[end]->is_find = 0;
    }
    dfs(graph1, 0);
    return 0;
}