#include <bits/stdc++.h>
using namespace std;

int chainMul(int *A, int s, int e){
    if(s==e){
        return 0;
    }
    int minVal = INT32_MAX;
    int a;
    for(int k = s; k<e; k++){
        a = chainMul(A, s,k)+chainMul(A, k+1, e)+(A[s-1]*A[k]*A[e]);
        minVal = min(a, minVal);
    }
    return minVal;

}


int main()
{
    int arr[] = {10 , 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<chainMul(arr, 1, n-1)<<endl; 
}