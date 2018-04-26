#include "stdio.h"

struct polynomial_1 {
    int coefficient;
    int index_1;
    int is_use;
};

struct polynomial_1 ans[500];

void quicksort(int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    struct polynomial_1 key = ans[left];
    while (i < j) {
        while (i < j && ans[j].index_1 <= key.index_1) {
            j--;
        }
        ans[i] = ans[j];
        while (i < j && ans[i].index_1 >= key.index_1) {
            i++;
        }
        ans[j] = ans[i];
    }
    ans[i] = key;
    quicksort(left, j - 1);
    quicksort(i + 1, right);
}

int main() {
    struct polynomial_1 x1[100];
    struct polynomial_1 x2[100];
    int i1 = 0;
    struct polynomial_1 p;
    scanf("%d%d", &p.coefficient, &p.index_1);
    x1[i1++] = p;
    while (getchar() != '\n') {
        scanf("%d%d", &p.coefficient, &p.index_1);
        x1[i1++] = p;
    }
    int j1 = 0;
    scanf("%d%d", &p.coefficient, &p.index_1);
    x2[j1++] = p;
    while (getchar() != '\n') {
        scanf("%d%d", &p.coefficient, &p.index_1);
        x2[j1++] = p;
    }
    int i, j;
    int label = 0;
    for (i = 0; i < i1; ++i) {
        for (j = 0; j < j1; ++j) {
            ans[label].coefficient = x1[i].coefficient * x2[j].coefficient;
            ans[label].index_1 = x1[i].index_1 + x2[j].index_1;
            ans[label].is_use = 0;
            label++;
        }
    }
    int k;
    quicksort(0, label - 1);
    for (k = 0; k < label; ++k) {
        if (ans[k].index_1 == ans[k + 1].index_1 && k != label - 1) {
            ans[k + 1].coefficient += ans[k].coefficient;
            continue;
        }
        printf("%d %d ", ans[k].coefficient, ans[k].index_1);
    }
}