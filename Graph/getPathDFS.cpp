#include<iostream>
#include<vector>
using namespace std;


vector<int>* getPath(int **edges, int n ,int s, int e, bool *visited){
    if(s==e){
        vector<int>* ans = new vector<int>;
        ans->push_back(s);
        return ans;
    }
    vector<int>* temp2 = NULL;
    visited[s] = true;
    for(int i = 0; i<n; i++){
        if(visited[i]){
            continue;
        }
        if(edges[s][i] == 1){
            vector<int>* temp = getPath(edges, n, i, e, visited);
            if(temp!= NULL){
                temp2 = temp;
                break;
            }
        }
    }
    if(temp2 != NULL){
        temp2->push_back(s);
    
    }
return temp2;
    
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
    vector<int>* s = getPath(edges, n, 0, 2, visited);
    for(int i= 0; i<n; i++){
        cout<<s->at(i)<<"->";
    }

}