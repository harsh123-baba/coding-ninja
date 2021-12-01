#include<iostream>
#include<queue>
using namespace std;

void Print(int **edges, int n, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    
    // cout<<sv<<endl;
    while(!q.empty()){
        
        int ele = q.front();
        cout<<ele<<endl;
        q.pop();
        for(int j = 0; j<n; j++){    
            
            if(edges[ele][j] == 1 && !visited[j]){
                q.push(j);
            visited[j] = true;   


            }
        
        }
    }

}


int main(){
    int n , e;
    cin>>n>>e;
    int** edges = new int*[n];
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
    Print(edges, n, 0, visited);

}