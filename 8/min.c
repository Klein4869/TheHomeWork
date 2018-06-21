#include "stdio.h"

typedef struct
{
    int value;
    int to;
}Min;


int graph1[100][100];
int graph2[100][100];
int target[100];
int counterTarget;
int isAdd[100];
Min min[100];

int main(int argc, char const *argv[])
{
    int d[100][100];
    int edgeNum, nodeNum, sumWeight;
    scanf("%d%d", nodeNum, edgeNum);
    int i, j;
    int edgeIndex, start, end, value;
    memset(isAdd, -1, sizeof(isAdd));
    for (i = 0; i < edgeNum; i++)
    {
        scanf("%d%d%d%d", edgeIndex, start, end, value);
        graph1[start][end] = value;
        graph1[end][start] = value;
        graph2[start][end] = edgeIndex;
        graph2[end][start] = edgeIndex;
    }
    start = 0;

    for (i = 0; i < 100; i++)
    {
        min[i].value = 100000;
        min[i].to = -1;
    }

    for (i = 0; i < nodeNum; i++)
    {

        for (i = 0; i < nodeNum; i++)
        {

            for (j = 0; j < nodeNum; j++)
            {

                if (graph1[i][j] == 0)
                {
                    continue;
                }

                if (graph1[i][j] < min[i].value)
                {
                    min[i].value = graph1[i][j];
                    min[i].to = j;
                }
            }
        }

        target[counterTarget++] = start;

        
        for(j = 0; j < counterTarget; j++)
        {
            /* code */
        }
        

        printf("%d\n", sumWeight);
    }

    return 0;
}
