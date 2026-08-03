#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	// Write your code here...
	int parent[100];

	for (int i = 0; i < V; i++)
		parent[i] = i;
	int edges = 0, mincost = 0;
	while (edges < V - 1)
	{
		int min = INT_MAX;
		int a = -1, b = -1;

		for (int i = 0; i < V; i++)
			{
				for (int j = i + 1; j < V; j++)
					{
						if (cost[i][j] < min)
						{
							min = cost[i][j];
							a = i;
							b = j;
						}
					}
			}

			if (a == -1)
				break;

		int u = a, v = b;

		while (parent[u] != u)
			u = parent[u];

		while (parent[v] != v)
			v = parent[v];

		if (u != v)
		{
					parent[v] = u;
					printf("Edge %d:(%d, %d) cost:%d\n", edges, a, b, min);
					mincost += min;
					edges++;
				}
		cost[a][b] = cost[b][a] = INT_MAX;
	}
	printf("Minimum cost= %d\n", mincost);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}