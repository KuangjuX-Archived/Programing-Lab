#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct graph {
    int edge[20][20];
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

void DFS(graph *G, int from, int m, vector<int> status) {
    if (from == m){
        for(int i=0; i<status.size(); i++){
            printf("%d ", status[i]);
        }
        printf("%d\n", m);
        return;
    }
    for(int i = from+1; i <= m; i++) {
        if (G->edge[from][i]==1) {
            status.push_back(from);
            DFS(G, i, m, status);
            status.pop_back();
        }
    }
}

int main() {
    graph G;
    new_graph(&G);
    int m, n;
    cin>>m>>n;

    for(int i = 0; i < n; i++) {
        int col, row;
        cin>>col>>row;
        add_edge(&G, col, row);
    }

    // vector<int> status;
    // int* status = new int[1000];
    vector<int> status;
    // status[0] = 1;
    DFS(&G, 1, m, status);
    return 0;

}

