#include<stdio.h>
#include<stdlib.h>
#include "prim.h"
#define limit 9999
#define MAX 20


int Prim(int G[MAX][MAX], int spanning[MAX][MAX], int n){
    int i, j, s, d;
    int min_distance, no_edges, min_weight;
    int visited[MAX], distance[MAX], from[MAX], weight[MAX][MAX];

    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            if(G[i][j] == 0)
                weight[i][j] = limit;
            else{
                weight[i][j] = G[i][j];
                spanning[i][j] = 0;
            }
        }

    distance[0]=0;
    visited[0]=1;

    for(i=1;i<n;i++){
        distance[i] = weight[0][i];
        from[i] = 0;
        visited[i] = 0;
    }

    min_weight = 0;
    no_edges = n-1;

    while(no_edges > 0){
        min_distance=limit;

        for(i=1; i<n; i++)
            if(visited[i] == 0 && distance[i] < min_distance){
                v = i;
                min_distance = distance[i];
            }

        u = from[v];

        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        no_edges--;
        visited[v]=1;

        for(i=1; i<n; i++)
            if(visited[i] == 0 && weight[i][v] < distance[i]){
                distance[i] = weight[i][v];
                from[i] = v;
            }

        min_weight = min_weight + weight[u][v];
    }

    return(min_weight);
}
