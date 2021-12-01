#include<iostream>
using namespace std;

bool hasPath(int **edges, int n,int s,int e,bool* visited){
    visited[s] = true;
    if(edges[s][e] == 1){
        return true;
    }
    bool ans = false;
    for(int i = 0; i<n; i++){
        
        if(visited[i]){
            continue;
        }
        if(edges[s][i] == 1){
            ans =  hasPath(edges, n, i, e, visited);
        }
    }
    return ans;
}

int main(){
    int n, e;
    cin>>n>>e;
    int ** edges = new int*[n];
    for(int i = 0; i<n; i++){
        edges[i] = new int[n];
        for(int j = 0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i<e; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }

    cout<<hasPath(edges, n, 0, 2, visited)<<endl;


    delete [] visited;
    for(int i = 0; i<n; i++){
        delete edges[i];
    }
    delete [] edges;

}