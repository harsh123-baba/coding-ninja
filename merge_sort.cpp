#include<iostream>
using namespace std;


void Merge(int A[], int si, int ei, int mid);
void MergeSort(int A[], int si, int ei){
    int mid;
    if(si<ei){
        mid = (si+ei)/2;
        MergeSort(A, si, mid);
        MergeSort(A, mid+1, ei);
        Merge(A, si, ei, mid);
    }
}


void Merge(int A[] , int si, int ei, int mid){
    int i = si;
    int k = si;
    int j = mid+1;
    int c[50];
    while(i<=mid && j <= ei){
        if(A[i]<A[j]){
            c[k] = A[i];
            i++;
            k++;
        }
        else{
            c[k] = A[j];
            j++;
            k++;

        }
    }
    while(i<=mid){
        c[k] = A[i];
        i++;
        k++;
    }
    while(j<=ei){
        c[k] = A[j];
        j++;
        k++;

    }
    for(i =0 ; i<k ; i++){
        A[i] = c[i];
    }

}


int main(){

    int A[] = {1, 7, 3, 4, 2, 9, 8};
    MergeSort(A, 0, 6);
    for(int i =0; i<7; i++){
        cout<<A[i]<<endl;
    }
}