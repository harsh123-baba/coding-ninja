#include<iostream>
using namespace std;

int longestSub(int *arr, int n){
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i<n; i++){
        int ans = 0;
        for(int j = i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                ans = max(dp[j], ans);
            }
        }
        dp[i] = ans+1;
    }
    int res = 0;
    for(int i = 0; i<n; i++){
        res = max(dp[i], res);

    }
    return res;

}


int longestSubRec(int *arr, int n , int prev, int currindex){
    if(currindex == n){
        return 0;
    }
    int taken = 0;
    if(arr[currindex] > prev){
        taken = 1+longestSubRec(arr, n, arr[currindex], currindex+1);
    }
    int nottaken = longestSubRec(arr, n, prev, currindex+1);
    return max(taken, nottaken);
}

int longestSubRec(int *arr, int n){
    
    return longestSubRec(arr, n , INT32_MIN, 0);
}

//Memoization

int longestMem(int *arr, int prevIndex, int currIndex, int n, int **dp){
    if(currIndex == n){
        return 0;
    }
    if(dp[prevIndex+1][currIndex] != -1){
        return dp[prevIndex+1][currIndex];
    }
    int taken=0;
    if(prevIndex<0 || arr[prevIndex]<arr[currIndex]){
        taken = 1+longestMem(arr, currIndex, currIndex+1, n, dp);
    }
    int nottaken = longestMem(arr, prevIndex, currIndex+1, n, dp);
    dp[prevIndex+1][currIndex] = max(taken, nottaken);
    return dp[prevIndex+1][currIndex];
}

int longestMem(int *arr, int n){
    int **dp = new int*[n+1];
    for(int i = 0; i<=n; i++){
        dp[i] = new int[n+1];
        for(int j = 0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    return longestMem(arr, -1, 0, n, dp);

}

// DP

int longestDP(int *arr, int n){
    int dp[n];
    dp[0] = 1;
    int ans = 1;


    for(int i = 1; i<n; i++){
        int maxval = 0;
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i]){
                maxval = max(maxval, dp[j]);
            }

        }
        dp[i] = maxval+1;
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main(){
    int n = 6;
    int arr[] = {5, 4, 11, 1, 16, 8};
    cout<<longestSub(arr, 6)<<endl;
    cout<<longestMem(arr, 6)<<endl;
    cout<<longestSubRec(arr, 6)<<endl;
    cout<<longestDP(arr, 6)<<endl;




}