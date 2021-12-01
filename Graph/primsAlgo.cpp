#include<iostream>
using namespace std;


int minimum(int *A, bool * visited){
    int n = sizeof(A)/sizeof(int);
    int min = INT32_MIN;
    int index = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i] && min<A[i]){
            min = A[i];
            index = i;
        }
    }
    return index;
}

void Prims(int **edges, int n){
    int *parent = new int[n];
    int * weight = new int[n];
    bool *visited = new bool[n];
    for(int i= 0; i<n; i++){
        visited[i] = false;
        weight[i] = INT32_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;
    // int i =0;
    // int count = 0;
    for(int i = 0;i<n; i++){
        int min = minimum(weight, visited);
        // find the index;
        visited[min] = true;
        for(int j=0; j<n; j++){
            if(edges[min][j] !=0){
                if(weight[j] > edges[min][j]){
                    parent[j] = min;
                    weight[j] = edges[min][j];
                }
            }
        }
        // count++;
    }
    for(int i = 0; i<n; i++){
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
    }
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
        int s, d, w;
        cin>>s>>d>>w;
        
            edges[s][d] = w;
            edges[d][s] = w;

    }
    cout<<endl;
    Prims(edges, n);

}