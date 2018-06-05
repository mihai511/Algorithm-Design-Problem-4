#define MAX 20

typedef struct edge{
    int s,d,w;
}edge;

typedef struct edgelist{
    edge data[MAX];
    int n;
}edgelist;

int Find(int belongs[],int no_vertices);
void Union(int belongs[],int c1,int c2, int n);
void Sort(edgelist elist);
void print(edgelist spanlist);
void Kruskal(int G[MAX][MAX], int spanning[MAX][MAX], int n, edgelist elist, edgelist spanlist);
