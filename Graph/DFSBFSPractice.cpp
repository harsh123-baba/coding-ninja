#include<iostream>
#include<queue>
using namespace std;


void PrintDFS(int ** edges, int n, int sv, bool * visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i = 0; i<n; i++){
        if(i==sv){
            continue;
        }   
        if(edges[sv][i]==1){
            if(!visited[i]){
                PrintDFS(edges, n, i, visited);
            }
        }     
    }
}   

void PrintBFS(int **edges, int n, int sv, bool *visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout<<ele<<" ";
        for(int  i = 0; i<n; i++){
            if(edges[ele][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            PrintDFS(edges, n, i, visited);
        }
    }    
}
void BFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            PrintBFS(edges, n, i, visited);
        }
    }
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

    BFS(edges, n);
    DFS(edges, n);
}