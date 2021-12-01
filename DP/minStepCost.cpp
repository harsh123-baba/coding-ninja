#include<iostream>
using namespace std;
// Brute Force 
int minCost(int **input, int m , int n, int i, int j){
    //Base case
    if(i == m-1 && j== n-1){
        return input[i][j];
    } 

    if(i >= m || j >= n){
        return INT32_MAX;
    }

    int x = minCost(input, m, n, i, j+1);
    int y = minCost(input, m, n, i+1 , j+1);
    int z = minCost(input, m, n, i+1, j);
    int ans = min(x, min(y, z))+input[i][j];
    return ans;

}

int minCost(int **input , int m, int n){
    return minCost(input, m, n, 0, 0);
}

//Memoization
int minCostMem(int **input, int m , int n, int i, int j, int **output){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i>= m || j>= n){
        return INT32_MAX;
    }
    
    if(output[i][j]!= -1){
        return output[i][j];
    }
    int x = minCostMem(input, m, n, i, j+1, output);
    int y = minCostMem(input, m, n, i+1, j+1, output);
    int z = minCostMem(input, m, n, i+1, j, output);
    int ans = min(x, min(y, z))+input[i][j];
    output[i][j] = ans;
    return output[i][j];
}

int minCostMem(int ** input, int m, int n){
    int ** output = new int*[m];
    for(int i = 0; i<m; i++){
        output[i] = new int[n];
        for(int j = 0; j<n; j++){
            output[i][j] = -1;
        }
    }
    return minCostMem(input, m, n, 0, 0, output);
}


// Dynamic program
int minCostDP(int **input, int m , int n){
    int i = 0;
    int j = 0;
    int **output = new int*[m];
    for(int i = 0; i<m; i++){
        output[i] = new int[n];
        for(int j = 0; j<n; j++){
            output[i][j] = 0;
        }
    }
    // last column fillig
    output[m-1][n-1] = input[m-1][n-1];
    for(int i = m-2; i>=0; i--){
        output[i][n-1] = output[i+1][n-1]  + input[i][n-1];
    }
    // last row filling
    for(int j = n-2; j>=0; j--){
        output[m-1][j] = output[m-1][j+1]+ input[m-1][j];
    }
    // remaing indexes filling;
    for(int i = m-2; i>=0; i--){
        for(int j = n-2; j>=0; j--){
            output[i][j] = min(output[i][j+1], min(output[i+1][j+1], output[i+1][j]))+input[i][j];
        }
    }
    return output[0][0];

}


int main(){
    // int **input;
    int m;
    int n;
    cin>>m>>n;
    int **input = new int*[m];
    for(int i = 0; i<m; i++){
        input[i] = new int[n];
        for(int j = 0; j<n; j++){
            cin>>input[i][j];
        }
    }
    cout<<minCostMem(input, m, n)<<endl;
    cout<<minCostDP(input, m, n)<<endl;

}