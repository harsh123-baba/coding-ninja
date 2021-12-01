#include<iostream>
using namespace std;

int SumOfArray(int A[], int n){
    int sum = 0;
    if(n==0){
        return sum;
    }
    sum = A[0] + SumOfArray(A+1 , n-1);
    return sum;

}

int main()
{
    int A[] = {1, 2, 3,4};
    cout<<SumOfArray(A, 4)<<endl;

}