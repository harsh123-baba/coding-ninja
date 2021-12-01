#include<iostream>
using namespace std;


int subarray(int A[],int size, int output[]){
    if(size==0){
        output[0] = {};
        return 1; 
    }

    int smallarray = subarray(A+1, size, output);
}


int main(){
    
}