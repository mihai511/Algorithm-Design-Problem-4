#include<stdio.h>
#include<stdlib.h>
#include "kruskal.h"
#define limit 9999
#define MAX 20

int Find(int belongs[],int no_vertices){
    return(belongs[no_vertices]);
}

void Union(int belongs[],int c1,int c2, int n){
    int i;

    for(i=0; i<n; i++)
        if(belongs[i] == c2)
            belongs[i] = c1;
}

void Sort(edgelist elist){
    int i, j;
    edge aux;

    for(i=1; i<elist.n; i++)
        for(j=0; j<elist.n-1; j++)
            if(elist.data[j].w > elist.data[j+1].w){
                aux = elist.data[j];
                elist.data[j] = elist.data[j+1];
                elist.data[j+1] = aux;
            }
}

void print(edgelist spanlist){
    int i, weight=0;

    for(i=0; i<spanlist.n; i++){
        printf("\n%d\t%d\t%d", spanlist.data[i].s, spanlist.data[i].d, spanlist.data[i].w);
        weight = weight + spanlist.data[i].w;
    }

    printf("\nThe weight of the spanning tree is %d", weight);
}

void Kruskal(int G[MAX][MAX], int spanning[MAX][MAX], int n, edgelist elist, edgelist spanlist){
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for(i=1; i<n; i++)
        for(j=0; j<i; j++)
            if(G[i][j] != 0){
                elist.data[elist.n].s = i;
                elist.data[elist.n].d = j;
                elist.data[elist.n].w = G[i][j];
                elist.n++;
            }


    Sort(elist);

    for(i=0; i<n; i++)
        belongs[i] = i;

    spanlist.n = 0;

    for(i=0; i<elist.n; i++){
        cno1 = Find(belongs, elist.data[i].s);
        cno2 = Find(belongs, elist.data[i].d);

        if(cno1 != cno2){
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n+1;
            Union(belongs,cno1,cno2,n);
        }
    }

    print(spanlist);
}


