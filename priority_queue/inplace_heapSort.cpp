#include<iostream>
using namespace std;

void swap(int& a, int& b){  
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void InplaceHeapSort(int input[], int n){
    
    // Build heap 
    // to incresing 
    for(int i = 1; i<n; i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            if(input[childIndex] < input[parentIndex]){
                swap(input[childIndex] , input[parentIndex]);
                childIndex = parentIndex;
            }
            else{
                break;
            }
            
        }
    }
    // remove element to get Decresing order array;
    // int size = n;
    // while(size>1){
    //     swap(input[0], input[size-1]);
    //     size--;
    //     int parentIndex = 0;
    //     int lchildIndex = 2*parentIndex+1;
    //     int rchildIndex = 2* parentIndex +2;
    //     while(lchildIndex < size){
    //         int minIndex = parentIndex;
    //         if(input[minIndex] > input[lchildIndex]){
    //             minIndex = lchildIndex;
    //         }
    //         if(rchildIndex < size &&  input[minIndex] > input[rchildIndex]){
    //             minIndex = rchildIndex;
    //         }
    //         if(minIndex == parentIndex){
    //             break;
    //         }
    //         swap(input[minIndex], input[parentIndex]);
    //         parentIndex = minIndex;
    //         lchildIndex = parentIndex*2 +1;
    //         rchildIndex = parentIndex*2 +2;
    //     }
    // }
}


int main(){
    int A[] = {5,1,1,2,0,0};
    InplaceHeapSort(A, 5);
    for(int i = 0; i<5; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}