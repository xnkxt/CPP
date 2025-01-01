#include <iostream>
using namespace std;

int main(){
    int node, edge;
    cin >> node >> edge;
    int adjancyMatrix[node+1][node+1];

    for(int i=0;i<edge;i++){
        int u, v;
        cin >> u >> v;
        adjancyMatrix[u][v]=1;
        adjancyMatrix[v][u]=1;
    }
    return 0;
}