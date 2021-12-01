#include<iostream>
using namespace std;

int getmaxMoney(int * arr, int n){
    if(n<=0){
        return 0;

    }
    int a = getmaxMoney(arr+2, n-2)+arr[0];
    int b = getmaxMoney(arr+1, n-1);
    return max(a, b);
}

// DP

int getMaxDP(int *arr, int n , int * dp){
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i = 2; i<n; i++){
        dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
    }
    return dp[n-1];

}
int getMaxDP(int *arr, int n){
    int *dp = new int[n];
    for(int i = 0; i<n; i++){
        dp[i] = 0;
    }
    return getMaxDP(arr, n, dp);

}

//best solution

int maxMoneyLooted (int* houses, int n)
{
    if(n == 0)
    {
        return 0;
    }
    
    if(n == 1)
    {
    	return houses[0];
    }

    if(n == 2)
    {
    	return max(houses[0], houses[1]);
    }

    int curr;                           // curr : dp[i]
    int prev1 = max(houses[0], houses[1]);    // prev1 : dp[i-1]
    int prev2 = houses[0];                 // prev2 : dp[i-2]

    for(int i=2; i<n; i++)
    {
    	curr = max(prev1, houses[i] + prev2);

    	prev2 = prev1;
    	prev1 = curr;
    }

    return curr;
}




int main(){
    int n;
    int A[] = {10 ,2, 30, 20, 3, 50};
    n = 6;
    cout<<getmaxMoney(A, n)<<endl;
    cout<<getMaxDP(A, n)<<endl;
}