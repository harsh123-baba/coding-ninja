#include<iostream>
using namespace std;

bool isSorted(int A[], int n){
    if(n==0 || n==1){
        return true;
    }
    if (A[0]>A[1]){
        return false;
    }
    bool smalloutput = isSorted(A+1, n-1);
    return smalloutput;
}

int main(){
    int A[] = {4, 2 , 3};
    cout<<isSorted(A, 3)<<endl;
    
}