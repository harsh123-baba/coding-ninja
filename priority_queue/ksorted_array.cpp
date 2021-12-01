// in this kind of array we have given a k where during sorting we gave a array
// after sorting that element is around k to its previous position
// lets suppose 10, 12, 6, 7 ,9
// in this 12 move 1 index 10 move 1, 9 move 2 index 
// as k value is 3 in this example so this is the valid array

// in this we dont need to trace full array again and again
// just check for A[k-1] in right and A[k-1] in left you will find the best element for this position

#include<iostream>
#include<queue>
using namespace std;

void Ksort(int A[], int n, int k){
    priority_queue<int> p;
    for(int i = 0; i<k; i++){
        p.push(A[i]); 
    }
    int j = 0;
    for(int i = k; i<n; i++){
        A[j] = p.top();
        p.pop();
        p.push(A[i]);
        j++;
    }
    while(!p.empty()){
        A[j] = p.top();
        p.pop();
    }
}

int main(){
    int A[] = {10, 12, 6, 7, 9};
    int k = 3;
    Ksort(A, 5, k);
    for(int i = 0; i<5; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

}