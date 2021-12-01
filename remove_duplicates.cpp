#include<iostream>
using namespace std;


void Merge(int *, int, int , int);
void MergeSort(int A[], int si, int ei){
    int mid;
    if(si<ei){
        mid =(si+ei)/2;
        MergeSort(A, si, mid);
        MergeSort(A, mid+1, ei);
        Merge(A, si, ei, mid);
    }
}

void Merge(int A[], int si, int ei, int mid){
    int i = si;
    int k = si;
    int j = mid+1;
    int c[50];
    while(i<=mid && j <= ei){
        if(A[i]<A[j]){
            c[k++] = A[i++];
        }
        else{
            c[k++] = A[j++];
        }

    }
    while(i<=mid){
        c[k++] = A[i++];
    }
    while(j<=ei){
        c[k++] = A[j++];
    }
    
}




int main(){
    int A[] = {1, 4, 3, 7, 5, 9, 2};
    MergeSort(A, 0, 7);
    for(int i =0; i<6; i++){
        cout<<A[i]<<endl;
    }
}



// #include <iostream>
// using namespace std;
// void merge(int *,int, int , int );
// void merge_sort(int *arr, int low, int high)
// {
//     int mid;
//     if (low < high){
//         //divide the array at mid and sort independently using merge sort
//         mid=(low+high)/2;
//         merge_sort(arr,low,mid);
//         merge_sort(arr,mid+1,high);
//         //merge or conquer sorted arrays
//         merge(arr,low,high,mid);
//     }
// }
// // Merge sort 
// void merge(int *arr, int low, int high, int mid)
// {
//     int i, j, k, c[50];
//     i = low;
//     k = low;
//     j = mid + 1;
//     while (i <= mid && j <= high) {
//         if (arr[i] < arr[j]) {
//             c[k] = arr[i];
//             k++;
//             i++;
//         }
//         else  {
//             c[k] = arr[j];
//             k++;
//             j++;
//         }
//     }
//     while (i <= mid) {
//         c[k] = arr[i];
//         k++;
//         i++;
//     }
//     while (j <= high) {
//         c[k] = arr[j];
//         k++;
//         j++;
//     }
//     for (i = low; i < k; i++)  {
//         arr[i] = c[i];
//     }
// }
// // read input array and call mergesort
// int main()
// {
//     int myarray[30], num;
//     cout<<"Enter number of elements to be sorted:";
//     cin>>num;
//     cout<<"Enter "<<num<<" elements to be sorted:";
//     for (int i = 0; i < num; i++) { cin>>myarray[i];
//     }
//     merge_sort(myarray, 0, num-1);
//     cout<<"Sorted array\n";
//     for (int i = 0; i < num; i++)
//     {
//         cout<<myarray[i]<<"\t";
//     }
// }