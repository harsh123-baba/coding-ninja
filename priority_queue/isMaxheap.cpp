#include<iostream>

using namespace std;

bool isMaxHeap(int A[], int n){
    // int size = n;
    for(int i = 0; i<=(n-2)/2; i++){
        int parentIndex = i;
        int lchildIndex = 2* parentIndex +1;
        int rchildIndex = 2*parentIndex +2;
        if(rchildIndex < n && A[rchildIndex] > A[parentIndex]){
            return false;
        }
        if(A[lchildIndex]> A[parentIndex]){
            return false;
        }
    }
    return true;
}


int main(){
    int A[] = {42, 20, 18, 6, 14, 11, 9, 4};
    cout<<isMaxHeap(A, 8)<<endl;
}