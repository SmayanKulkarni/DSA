#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define V 4

void FloydWarshall(int graph[V][V]){
    int dist[V][V], i,j,k;

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            dist[i][j] = graph[i][j];
        }
    }
    for(k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

    }

    printf("The following matrix shows the shortest distances between every pair of vertices \n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(dist[i][j]==INF){
                printf("%7s","INF");
            }
            else{
                printf("%7d",dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    FloydWarshall(graph);
    return 0;
}