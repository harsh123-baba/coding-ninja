#include<iostream>
using namespace std;

int minVertex(int *A, bool *visited){
    int n = sizeof(A)/sizeof(int);
    int minDistance = -1;
    for(int i =0; i<n; i++){
        if(!visited[i] &&( minDistance == -1 ||A[i] < A[minDistance])){
            minDistance = i;
        }
    }
    return minDistance;
}

void Dijsktra(int **edges, int n){
    bool * visited = new bool [n];
    int * distance = new int[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
        distance[i] = INT32_MAX;
    }
    distance[0] = 0;
    // find the min distance vertex;
    for(int i = 0; i<n-1; i++){
        int minDistance = minVertex(distance, visited);
        visited[minDistance] = true;
        for(int j = 0; j<n; j++){
            if(edges[minDistance][j]!=0 && !visited[j]){
                int dist = distance[minDistance]+edges[minDistance][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout<<i<<" "<<distance[i]<<"\n";
    }

}


int main(){
    int n, e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i = 0; i<n; i++){
        edges[i] = new int[n];
        for(int j = 0; j<n; j++){
            edges[i][j] =0;
        }
    }
    for(int i = 0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    Dijsktra(edges, n);

}