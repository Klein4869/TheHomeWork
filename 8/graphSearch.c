#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int value;
    struct node *next;
}node;

typedef struct graph {
    node *node_list[100];
    int is_find[100];
    int node_num;
    int side_num;
}Graph;

typedef struct queue {
    node *q[100];
    node *head;
    node *end;
}Queue;

void bfs(Graph *graph1, int i) {
    Queue q;
    int count = 1;
    int head = 0;
    node *temp;
    printf("%d ", i);
    graph1->is_find[i] = 1;
    if (graph1->is_find[graph1->node_list[i]->value] == 0) {
        q.q[head] = graph1->node_list[i];
        q.head = q.q[head++];
        graph1->is_find[graph1->node_list[i]->value] = 1;
        temp = graph1->node_list[i]->next;
    } else{
        q.q[head] = graph1->node_list[i]->next;
        q.head = q.q[head++];
        graph1->is_find[graph1->node_list[i]->next->value] = 1;
        temp = graph1->node_list[i]->next->next;
    }
    while (temp){
        if (graph1->is_find[temp->value] == 0) {
            q.q[count++] = temp;
            graph1->is_find[temp->value] = 1;
        }
        temp = temp->next;
    }
    q.end = q.q[count];
    while (q.head != q.end)
    {
        node *n = (node*)malloc(sizeof(node));
        n = graph1->node_list[q.head->value];
        while (n){
            if (graph1->is_find[n->value] == 0) {
                q.q[count++] = n;
                graph1->is_find[n->value] = 1;
                q.end =  q.q[count];
            }
            n = n->next;
        }
        printf("%d ", q.head->value);
        q.head = q.q[head++];
    }
}

void dfs(Graph *graph1, int i) {
    if (graph1->is_find[i] == 0) {
        printf("%d ", i);
        graph1->is_find[i] = 1;
    }
    else
        return;
    node *n_temp = graph1->node_list[i];
    while (n_temp) {
        dfs(graph1, n_temp->value);
        n_temp = n_temp->next;
    }
}

node *sort(node *head) {
    node *first, *t, *q;
    node *p=NULL;
    first = head->next;
    head->next = NULL;
    while (first != NULL){
        for (t = first, q = head; ((q != NULL) && (q->value < t->value));p=q,q=q->next);
        first = first->next;
        if (q == head)
            head = t;
        else
            p->next = t;
        t->next = q;
    }
    return head;
}

int main() {
    Graph graph1;
    int i, j, k, node_num, side_num;
    scanf("%d%d", &node_num, &side_num);
    graph1.node_num = node_num;
    for (i = 0; i < graph1.node_num; ++i) {
        graph1.node_list[i] = NULL;
        graph1.is_find[i] = 0;
    }
    node *node1;
    for (i = 0; i < side_num; ++i) {
        int start, end;
        scanf("%d%d", &start, &end);
        node1 = (node*)malloc(sizeof(node));
        node1->value = end;
        node1->next = graph1.node_list[start];
        graph1.node_list[start] = node1;
        node1 = (node*)malloc(sizeof(node));
        node1->value = start;
        node1->next = graph1.node_list[end];
        graph1.node_list[end] = node1;
    }
    for ( i = 0; i < node_num; i++)
        graph1.node_list[i] = sort(graph1.node_list[i]);
    dfs(&graph1, 0);
    printf("\n");
    for (i = 0; i < node_num; i++)
        graph1.is_find[i] = 0;
    bfs(&graph1, 0);
    printf("\n");
    int delete_num;
    scanf("%d", &delete_num);
    for (i = 0; i < node_num; i++)
        graph1.is_find[i] = 0;
    graph1.is_find[delete_num] = 1;
    if (delete_num == 0)
        dfs(&graph1, 1);
    else
        dfs(&graph1, 0);
    printf("\n");
    for (i = 0; i < node_num; i++)
        graph1.is_find[i] = 0;
    graph1.is_find[delete_num] = 1;
    if (delete_num == 0)
        bfs(&graph1, 1);
    else
        bfs(&graph1, 0);
    return 0;
}