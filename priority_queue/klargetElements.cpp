#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int> , greater<int>> KlargestElement(int A[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> p;
    for(int i = 0; i<k ; i++){
        p.push(A[i]);
    }
    for(int i = k; i<n; i++){
        if(A[i]>p.top()){
            p.pop();
            p.push(A[i]);
        }
    }
    return p;
}

int main(){
    int A[] = {10, 12, 6, 7, 9, 15};
    priority_queue<int, vector<int>, greater<int>> p = KlargestElement(A, 6, 2);
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }

}