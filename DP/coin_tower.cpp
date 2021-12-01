#include<iostream>
using namespace std;


bool coinTower(int n, int x, int y){
    int dp[n] = {0};
    // int i = 0;
    
    dp[1] = 1;
    dp[n-x] = 1;
    dp[n-y] = 1;
    for(int i = 2; i<n ; i++){
        if(dp[i-1]^1 || ( i-x >=1 &&dp[i-x]^1) || (i-y>=1 && dp[i-y]^1)){
            dp[i] = 1;
        }
    }
    if(dp[n-1] != 0){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    int n, x, y;
    // n = 4;
    // x = 2;
    // y = 3;
    cin>>n>>x>>y;
    if(coinTower(n, x, y)){
        cout<<"Berus";
    }
    else{
        cout<<"Wins";
    }

}