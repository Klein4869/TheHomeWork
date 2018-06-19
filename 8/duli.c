#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node {
	int value;
	struct node *next;
} node;

typedef struct graph {
	node *nodeList[100];
	int node_num;
	int side_num;
} Graph;

int graph[100][100][100];
int count[100][100];
int isFind[100];
char result[100][100];
int counter = 0;
int counter1 = 0;

void search(int start, int end) {
	int i, j, k, l;
	char num[5];
	if (start == end) {
		strcpy(result[counter1+1], result[counter1]);
		counter1++;
		return;
	}
	if (isFind[start] != 0)
		return;
	for (j = 1; j <= end; ++j) {
		for (k = 0; k < count[start][j]; ++k) {
			if (graph[start][j][k] == 0) continue;
			snprintf(num, 5, "%d", graph[start][j][k]);
			strcat(result[counter1], num);
			counter += strlen(num);									 
			search(j, end);
			counter -= strlen(num);
			for (l = 0; l < strlen(num); ++l) result[counter1][counter + l] = '\0';
		}
	}
}

void sort(int left, int right) {
	if (left >= right)
		return;
	int i = left;
	int j = right;
	char key[100];
	strcpy(key, result[left]);
	while (i < j){
		while (i < j && strcmp(result[j], key) > 0) j--;
		strcpy(result[i], result[j]);
		while (i < j && strcmp(result[i], key) < 0) i++;
		strcpy(result[j], result[i]);
	}
	strcpy(result[i], key);
	sort(left, i - 1);
	sort(j + 1, right);
}

int main() {
	int node_num, side_num, i, j, k, node_index, start, end;
	for (i = 0; i < 100; ++i) {
		isFind[i] = 0;
		for (j = 0; j < 100; ++j) {
			result[i][j] = '\0';
			count[i][j] = 0;
			for (k = 0; k < 100; ++k) graph[i][j][k] = 0;
		}
	}
	scanf("%d%d", &node_num, &side_num);
	for (i = 0; i < side_num; ++i) {
		scanf("%d%d%d", &node_index, &start, &end);
		graph[start][end][count[start][end]++] = node_index;
	}
	start = 0;
	end = node_num - 1;
	search(start, end);
	sort(0, counter1 - 1);
	for (i = 0; i < counter1; ++i) {
		for (j = 0; j < strlen(result[i]); j++){printf("%c ", result[i][j]);}
		printf("\n");
	}
	getchar();
	getchar();
}