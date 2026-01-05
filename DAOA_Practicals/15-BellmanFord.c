#include <stdio.h>
#include <stdlib.h>

#define INF 999999

void BellmanFord(int n, int graph[n][n], int source)
{
    int dist[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }

    dist[source] = 0;

    /* Relax all edges n-1 times */
    for (int iter = 0; iter < n - 1; iter++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (graph[u][v] != INF)
                {
                    if (dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }
    }

    /* Check for negative-weight cycles */
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != INF && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    printf("Vertex Distance from Source (%d):\n", source);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main(){
    int i, j, n, u;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 1;

    /* declare adjacency matrix with runtime size (VLA) */
    int G[n][n];

    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if (scanf("%d", &G[i][j]) != 1) return 1;
        }
    }

    /* FIXED: convert user-entered 0 (no edge) to INF sentinel, but keep 0 on diagonal */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i != j && G[i][j] == 0)
                G[i][j] = INF;
        }
    }

    printf("Enter starting node (0-based index): ");
    if (scanf("%d", &u) != 1) return 1;

    if (u < 0 || u >= n){
        fprintf(stderr, "Invalid source node.\n");
        return 1;
    }

    BellmanFord(n, G, u);
    return 0;
}