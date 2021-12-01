#include<iostream>
using namespace std;

int last_index(int A[], int size, int x, int curr){
    if(size==0){
        return -1;
    }
    if (A[curr]==x){
        return curr+2;
    }
    // int ans;
     return last_index(A+1, size-1, x, curr+1);
}

int main(){
    int A[] = {1, 2, 3, 2};
    cout<<last_index(A, 4, 2, 0);
}