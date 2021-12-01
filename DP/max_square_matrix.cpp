#include<iostream>

using namespace std;

int MaxSquare(int ** v, int m, int n){
    int dp[m][n];
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            dp[i][j] = 0;
        }
    }

    if(v[0][0] == 0){
        dp[0][0] = 1;
    }

    else{
        dp[0][0] = 0;
    }

    for(int i = 0; i<m; i++){
        if(v[i][0] == 0){
            dp[i][0] = 1;
        }
        else{
            dp[i][0] = 0;
        }
    }

    for(int j = 0; j<m; j++){
        if(v[j][0] == 0){
            dp[j][0] = 1;
        }
        else{
            dp[j][0] = 0;
        }
    }

    for(int i = 1; i<m-1; i++){
        for(int j = 1; j<n-1; j++){
            if(v[i][j] == 0){
                dp[i][j] = min(v[i-1][j-1], min(v[i-1][j], v[i][j-1]))+1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return dp[m][n];    
}

int main(){
    int m, n;
    cin>>m>>n;
    int**v = new int*[m];
    for(int i = 0; i<m; i++){
        v[i] = new int[n];
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
        }
    }

    cout<<MaxSquare(v,m,n);

}