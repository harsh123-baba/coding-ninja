#include<iostream>
using namespace std;



int noOfIslandsHelper(int **edges, int n, bool* visited, int sv){
    visited[sv]= true;
    int x; 
    for(int i = 0; i<n; i++){
        if(i==sv){
            continue;
        }

        if(edges[sv][i]){
            if(visited[i]){
                continue;
            }
            x = noOfIslandsHelper(edges, n, visited, i)+1;
            // count++;
        }
    }
    return x;
}
int noOfIslands(int **edges, int n){
    bool *visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    int x;
    for(int i = 0;i<n; i++){
        if(!visited[i]){
            x = noOfIslandsHelper(edges, n, visited, i);
        }
        else{
            continue;
        }
    }

    return x;
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
    
    int count = 1;
    cout<<noOfIslands(edges, n)<<endl;
}