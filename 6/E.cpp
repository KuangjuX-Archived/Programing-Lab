#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct graph {
    int edge[20][20];
    int vertices;
};

void new_graph (graph *G) {
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++) {
            G->edge[i][j] = 0;
        }
    }
}

void add_edge(graph *G, int col, int row) {
    G->edge[col][row] = 1;
}

void DFS(graph *G, vector<int> status, int from) {
    if (from == G->vertices){
        for(int i=0; i<status.size(); i++){
            printf("%d ", status[i]);
        }
        printf("%d\n", G->vertices);
        return;
    }
    for(int i = from+1; i <= G->vertices; i++) {
        if (G->edge[from][i]==1) {
            status.push_back(from);
            DFS(G, status, i);
            status.pop_back();
        }
    }
}

int main() {
    graph G;
    new_graph(&G);
    int m, n;
    cin>>m>>n;

    G.vertices = m;

    for(int i = 0; i < n; i++) {
        int col, row;
        cin>>col>>row;
        add_edge(&G, col, row);
    }

    vector<int> status;
    DFS(&G, status, 1);
    return 0;

}

