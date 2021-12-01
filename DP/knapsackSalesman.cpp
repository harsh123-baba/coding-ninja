#include<vector>
#include<iostream>
using namespace std;
int knapsackDP(vector<int> weight, vector<int>& value, int n, int w){
    int **ans =  new int*[2];
    for(int i = 0; i<2; i++){
        ans[i] = new int[w+1];
        for(int j = 0; j<=w; j++){
            ans[i][j] = 0;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 1; j<= w; ++j){
            if(weight[i] <= j){
                ans[i%2][j] = max(value[i]+ans[(i+1)%2][j-weight[i]], ans[(i+1)%2][j]);
            }
            else{
                ans[i%2][j] = ans[(i+1)%2][j];
            }
        }
    }
    return ans[(n+1)%2][w];

}

int salesMan(vector<int> profit, vector<int>dist, int n, int d){
    vector<vector<int>> ans(2, vector<int>(d + 1, 0));
    for(int i = 0; i<n; i++){
        for(int j =1; j<=d; ++j){
            if(dist[i] <=j){
                ans[i%2][j] = max(profit[i]+ans[(i+1)%2][j-profit[i]], ans[(i+1)%2][j]);
            }
            else{
                ans[i%2][j] = ans[(i+1)%2][j];
            }
        }

    }
    return ans[(n+1)%2][d];
}

int main(){
    int n = 5;
    vector<int> weight = {5, 1, 8, 9, 2};
    vector<int> value = {4, 10, 2, 3, 1}; 
    int w = 15;
    cout<<salesMan(weight, value, n, w)<<endl;
}