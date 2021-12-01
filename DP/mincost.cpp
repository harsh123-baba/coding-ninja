#include<iostream>
#include<vector>
using namespace std;
int minCostClimbingStairs(vector<int>& cost, int i){
    if(i==cost.size()){
        return 0;
    }
    if(i >= cost.size()){
        return INT32_MAX;
    }
    int a = minCostClimbingStairs(cost,i+1);
    int b = minCostClimbingStairs(cost, i+2);
    int ans = min(a, b)+cost[i];
    return ans;
}
    
int minCostClimbingStairs(vector<int>& cost) {
    return minCostClimbingStairs(cost, 0);   
}

int main(){
    vector<int> cost = {10, 15, 20};
    cout<<minCostClimbingStairs(cost);
}