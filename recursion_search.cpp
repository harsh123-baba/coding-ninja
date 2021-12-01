#include<iostream>
using namespace std;

bool Search(int A[], int size, int n){
    if(A[0]==n){
        return true;
    }
    if (size==0){
        return false;
    }

    bool small = Search(A+1, size-1, n);
    // return small;
    return small;
}

int main(){

    int A[] = {1 , 2, 3,4};
    cout<<Search(A,4, 5)<<endl;

}