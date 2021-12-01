
#include<iostream>
#include<vector>
using namespace std;


bool* PrintDFS(int** edges, int n, int sv, bool *visited ){
    // cout<<sv<<" ";
    visited[sv] = true;
    for(int i = 0; i<n; i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            PrintDFS(edges, n, i, visited);
        }
    }
    return visited;
}



int main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
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
    bool * v = PrintDFS(edges, n, 0, visited);
    int flag = 0;
    for(int i = 0; i<n; i++){
        if(v[i] == false){
            flag =1;
            break;
        }
    }
    if(flag == 0){
        cout<<"Chl mje kr \n";
    }
    else{
        cout<<"lg Gye \n";
    }

}