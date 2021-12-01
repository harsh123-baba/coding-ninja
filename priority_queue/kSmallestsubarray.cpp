#include<iostream>
#include<queue>

using namespace std;
void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Ksmallest(int A[], int n, int k){
    priority_queue<int> p;
    for(int i = 0; i<k; i++){
        p.push(A[i]);
    }
    for(int i = k ; i<n; i++){
        if(A[i] < p.top()){
            int top = p.top();
            p.pop();
            p.push(A[i]);
            A[i] = top;
        }
    }
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
}

int main(){
    int A[] = {10, 12, 6, 7, 9, 15};
    Ksmallest(A, 6, 3);
}