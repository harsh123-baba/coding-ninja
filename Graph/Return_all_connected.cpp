#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>*>* val = NULL;

vector<vector<int>*>* AllComponent(int **edges , int n, int s,  bool* visited){
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }

    for(int i = 0; i<n;i++){
        if(edges[s][i] ==1){
            vector<int>* valinside = new vector<int>;
            visited[i] = true;
            valinside->push_back(i);
        }

    }
    
}


int main(){

}