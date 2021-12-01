#include<iostream>
using namespace std;

int first_index(int A[], int size, int e, int curr){

    if(size==0){
        return -1;
    }
    if(A[curr]==e){
        return curr+2;
    }
    int ans = first_index(A+1, size-1, e, curr+1);
    return ans;
}

int main(){
    int A[] = {2, 2, 3};
    cout<<first_index(A, 3, 3,0);
}
