#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source;
    int dest;
    int weight;

};


bool compare(Edge e1, Edge e2){
    return (e1.weight< e2.weight);
}

int findParent(int v, int *parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v], parent);
}

void Kruskal(Edge *input, int n, int e){
    sort(input , input+e, compare);
    int *parent = new int[n];
    for(int i = 0; i<n; i++){
        parent[i] = i;
    }
    Edge * output = new Edge[n-1];    
    int count = 0;
    int i = 0;
    while(count!=n-1){
        Edge currEdge = input[i];
        int sourceParent = findParent(currEdge.source, parent);
        int destParent = findParent(currEdge.dest, parent);
        if(sourceParent != destParent){
            output[count] = currEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
        
    }
    for(int i = 0; i<n-1; i++){
        cout<<output[i].source <<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }


}





int main(){
    int n, e;
    cin>>n>>e;
    Edge *input = new Edge[e];

    for(int i = 0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;   
    }   
    Kruskal(input, n, e);
}