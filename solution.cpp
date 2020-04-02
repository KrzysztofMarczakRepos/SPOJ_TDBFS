#include <iostream>

using namespace std;

void innerDFS(int** graph, int* adjCount, int vCount, int n, bool* visited){
    if(visited[n]==true) return;
    visited[n] = true;
    cout<<n+1<<" ";
    for(int i=0; i<adjCount[n]; i++)
        innerDFS(graph, adjCount, vCount, graph[n][i], visited);
}

void dfs(int** graph, int* adjCount, int vCount, int n){
    bool* visited = new bool[vCount];
    innerDFS(graph, adjCount, vCount, n-1, visited);
}

void innerBFS(int** graph, int* adjCount, int vCount, int n, int* visited, int* queue, int* q){
    if(visited[n] == 2) return;
    visited[n] = 2;
    cout<<n+1<<" ";
    for(int i=0; i<adjCount[n]; i++)
        if(visited[graph[n][i]] == 0){
            queue[++*q] = graph[n][i];
            visited[graph[n][i]] = 1;
        }
}

void bfs(int** graph, int* adjCount, int vCount, int n){
    int* visited = new int[vCount];
    int* queue = new int[vCount];
    int p, q;
    q = -1;
    p = 0;
    queue[++q] = n-1;
    while(p <= q && p < vCount){
        innerBFS(graph, adjCount, vCount, queue[p++], visited, queue, &q);
    }
    /*cout<<endl<<"queue: "<<endl;
    for(int i=0; i<vCount; i++)
        cout<<queue[i]+1<<" ";
    cout<<endl;
    */
}

int main(){
    int q;
    cin>>q;
    int grNum=1;
    while(q--){
        int vCount;
        cin>>vCount;
        int* graph[vCount];
        int* adjCount = new int[vCount];

        for(int i=0; i<vCount; i++){
            int current;
            cin>>current;
            cin>>adjCount[--current];
            graph[current] = new int [adjCount[current]];
            for(int j=0; j<adjCount[current]; j++){
                cin>>graph[current][j];
                graph[current][j]--;
            }
        }
        int v, method;
        cout<<"graph "<<grNum++<<endl;
        cin>>v;
        cin>>method;
        do{ 
            if(method)  bfs(graph, adjCount, vCount, v);
            else dfs(graph, adjCount, vCount, v);
            cin>>v;
            cin>>method;
            cout<<endl;
        }
        while(!(v==0));
    }
    return 0;
}