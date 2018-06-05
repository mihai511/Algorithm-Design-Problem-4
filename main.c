#include<stdio.h>
#include<stdlib.h>
#include "prim.h"
#include "kruskal.h"
#define limit 9999
#define MAX 20


int G[MAX][MAX], spanning[MAX][MAX], n;
edgelist spanlist, elist;

int main(){
    int i;
    int j;
    int total_weight;

    printf("Enter the number of vertices:");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:\n");

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&G[i][j]);

    printf("\nMetoda Prim:\n");

    total_weight = Prim(G, spanning, n);
    printf("\nspanning tree matrix:\n");

    for(i=0; i<n; i++){
        for(j=0; j<n; j++)
            printf("%d\t", spanning[i][j]);
        printf("\n");
    }

    printf("\nThe cost of spanning tree =%d", total_cost);

    printf("\nMetoda Kruskal:\n");

    Kruskal(G, spanning, n, elist, spanlist);

    scanf("%d", &n);

    return 0;
}
