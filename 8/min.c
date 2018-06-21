#include "stdio.h"

typedef struct
{
	int value;
	int to;
} Min;

typedef struct
{
	int start;
	int end;
}Ans;

int graph1[100][100];
int graph2[100][100];
int target[100];
Ans ans[100];
int counterTarget;
int counterAns;
int isAdd[100];
Min min[100];

int main(int argc, char const *argv[])
{
	int d[100][100];
	int edgeNum, nodeNum, sumWeight = 0;
	scanf("%d%d", &nodeNum, &edgeNum);
	int i, j, k;
	int edgeIndex, start, end, value;
	memset(isAdd, -1, sizeof(isAdd));
	for (i = 0; i < edgeNum; i++)
	{
		scanf("%d%d%d%d", &edgeIndex, &start, &end, &value);
		graph1[start][end] = value;
		graph1[end][start] = value;
		graph2[start][end] = edgeIndex;
		graph2[end][start] = edgeIndex;
	}
	start = 0;

	for (i = 0; i < 100; i++)
	{
		
		target[i] = -1;
	}

	for (i = 0; i < nodeNum; i++)
	{
		target[counterTarget++] = start;
		for (j = 0; j < 100; j++)
		{
			min[j].value = 100000;
			min[j].to = -1;
		}
		for (i = 0; i < counterTarget; i++)
		{

			for (j = 0; j < nodeNum; j++)
			{
				int flag = 0;
				for ( k = 0; k < counterTarget; k++)
				{
					if (target[k] == j)
					{
						flag = 1;
					}
				}
				if (graph1[target[i]][j] == 0 || flag == 1)
				{
					continue;
				}

				if (graph1[target[i]][j] < min[target[i]].value)
				{
					min[target[i]].value = graph1[target[i]][j];
					min[target[i]].to = j;
				}
			}
		}

		Min minAll;
		minAll.value = 10000;
		int add_index;

		for (j = 0; j < counterTarget; j++)
		{
			if (minAll.value > min[target[j]].value) {
				minAll = min[target[j]];
				ans[counterAns].start = target[j];
				ans[counterAns].end = minAll.to;
				start = min[target[j]].to;
				add_index = target[j];
			}
		}
		isAdd[add_index] = 1;

		counterAns++;
		sumWeight += minAll.value;
	}
	target[counterTarget++] = start;
	printf("%d\n", sumWeight);
	int ans1[100];
	for (i = 0; i < 100; i++)
	{
		ans1[i] = 10000;
	}
	for (i = 0; i < counterAns; i++)
	{
		ans1[i] = graph2[ans[i].start][ans[i].end];
	}
	int min = ans1[0];
	int flag1;
	for (i = 0; i < counterAns; i++)
	{
		for (j = 0; j < counterAns; j++)
			if (min >= ans1[j])
			{
				min = ans1[j];
				flag1 = j;
			}
		ans1[flag1] = 10000;
		printf("%d ", min);
		min = ans1[0];
	}
	getchar();
	getchar();
	return 0;
}
