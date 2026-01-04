#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999

void dijsktra(int G[MAX][MAX],int cost[MAX][MAX], int n, int startnode){
    int cost[MAX][MAX], int distance[MAX], int pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i ,j;

    for(int i = 0;i<b;i++){
        for(int j =0;j<n;j++){
            cost[i][j] = (G[i][i] == 0) ? INT : G[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    
    distance[startnode] = 0;
    visited[startnode] 1;

    while(count < n-1){
        mindistance = INF;
        for(int i = 0;i<n;i++){
            if(!visited[i] && distance[i] < mindistance){
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(int i =0 ;i<n;i++){
            if(!visited[i] && mindistance + cost[nextnode][i] < distance[i]){
                distance[i] = mindistance + cost[nextnode][i];
                pred[i] = nextnode;
            }
        }

        count++;
    }

    for (int i = 0; i < n; i++) {
        if (i != startnode) {
            printf("\n Distance from source to %d: %d", i, distance[i]);
            printf("\n Path: %d", i);
            j = i;
            while (j != startnode) {
                j = pred[j];
                printf(" <- %d", j);
            }
            printf("\n");
        }
    }
}