#include<iostream>
#include<vector>
using namespace std;

int knapsackMem(vector<int>& weight, vector<int>& value, int n, int w, int **output){
    if(n==0 || w==0){
        return 0;
    }
    if(output[n][w] != -1){
        return output[n][w];
    }
    int a = knapsackMem(weight, value, n-1, w, output);
    int q=0;
    if(w>=weight[n-1]){
        q = value[n-1] + knapsackMem(weight, value, n-1, w-weight[n-1], output);

    }
    output[n][w] = max(a, q);
    return output[n][w];
}

int knapsackMem(vector<int>& weight, vector<int>&value, int n, int w){
    int **output = new int*[n+1];
    for(int i =0; i<=n; i++){
        output[i] = new int[w+1];
        for(int j = 0; j<=w; j++){
            output[i][j] = -1;
        }
    }
    return knapsackMem(weight, value, n, w, output);
}

int main(){
    int n = 5;
    vector<int> weight = {5, 1, 8, 9, 2};
    vector<int> value = {4, 10, 2, 3, 1}; 
    int w = 15;
    // cout<<knapsack(weight, value, n, w)<<endl;
    cout<<knapsackMem(weight, value, n, w)<<endl;

}