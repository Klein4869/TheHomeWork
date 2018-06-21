#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node
{
	int value;
	struct node *next;
} node;

typedef struct graph
{
	node *nodeList[100];
	int node_num;
	int side_num;
} Graph;

int is_print[100];
int graph[100][100][100];
int count[100][100];
int isFind[100];
int result[100][100];
int counter = 0;
int counter1 = 0;

void search(int now, int end)
{
	if (now == end)
	{
		int i;
		for (i = 0; i < counter; i++)
		{
			result[counter1 + 1][i] = result[counter1][i];
		}
		counter1++;
		return;
	}
	int j, k, l;
	for (j = 1; j <= end; ++j)
	{
		if (isFind[j] || count[now][j] == 0)
		{
			continue;
		}
		for (k = 0; k < count[now][j]; k++)
		{
			result[counter1][counter++] = graph[now][j][k];
			isFind[j] = 1;
			search(j, end);
			isFind[j] = 0;
			result[counter1][counter--] = 0;
		}
	}
}

int main()
{
	int node_num, side_num, i, j, k, edge_index, start, end;
	for (i = 0; i < 100; ++i)
	{
		isFind[i] = 0;
		for (j = 0; j < 100; ++j)
		{
			result[i][j] = '\0';
			count[i][j] = 0;
			for (k = 0; k < 100; ++k)
				graph[i][j][k] = 0;
		}
	}
	isFind[0] = 1;
	scanf("%d%d", &node_num, &side_num);
	//    printf("%d %d\n", node_num, side_num);
	for (i = 0; i < side_num; ++i)
	{
		scanf("%d%d%d", &edge_index, &start, &end);
		//        printf("%d %d %d\n", edge_index, start, end);
		graph[start][end][count[start][end]++] = edge_index;
		graph[end][start][count[end][start]++] = edge_index;
	}
	start = 0;
	int min, num;
	end = node_num - 1;
	search(start, end);
	for (num = 0; num < counter1; ++num)
	{
		min = 0;
		for (i = 0; i < counter1; i++)
		{
			if (is_print[min])
			{
				min++;
				continue;
			}
			if (is_print[i] || min == i)
			{
				continue;
			}

			for (k = 0; result[min][k] != 0 && result[i][k] != 0; k++)
			{

				if (result[min][k] > result[i][k])
				{
					min = i;
					break;
				}
				if (result[min][k] < result[i][k])
				{
					break;
				}
			}
		}

		j = 0;
		for (; result[min][j] != 0; j++)
		{
			printf("%d ", result[min][j]);
			is_print[min] = 1;
		}
		printf("\n");
	}
}
