#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void heapsort(int A[], int size){

    //for decresing order
    for(int i = 1; i<size; i++){
        //now perform insert operation;
        int childIndex = i;
        while(childIndex>0){
            int parentIndex = childIndex-1;
            if(A[parentIndex] < A[childIndex]){
                swap(A[parentIndex], A[childIndex]);
                childIndex = parentIndex;
            }
            else{
                break;
            }
        }
    }

    //for incresing order
    int n = size;
    while(n >1){
        swap(A[n-1], A[0]);
        n--;
        int parentIndex = 0;
        int lchildIndex = 2*parentIndex+1;
        int rchildIndex = 2* parentIndex +2;
        while(lchildIndex<n){
            int maxIndex = parentIndex;
            if(A[maxIndex] < A[lchildIndex]){
                maxIndex = lchildIndex;
            }
            if(rchildIndex <n && A[maxIndex] < A[rchildIndex]){
                maxIndex = rchildIndex;
            }
            if(maxIndex == parentIndex){
                break;
            }
            swap(A[maxIndex], A[parentIndex]);
            parentIndex = maxIndex;
            lchildIndex = 2* parentIndex +1;
            rchildIndex = 2* parentIndex +2;
        }
    }
}


int main(){
    int A[] = {10, 15, 4, 100, 6, 17, 21, 57};
    int size = 8;
    heapsort(A, size);
    for(int i = 0; i<size; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}