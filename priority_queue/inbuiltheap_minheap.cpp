#include<iostream>
#include<queue>
using namespace std;


int main(){
    // for decresing 
    priority_queue<int>p;
    p.push(16);
    p.push(6);
    p.push(26);
    p.push(36);
    p.push(76);
    p.push(46);

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;

    // for incresing
    priority_queue<int , vector<int>, greater<int>>q;
    q.push(6);
    q.push(26);
    q.push(36);
    q.push(16);
    q.push(76);
    q.push(46);
   while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}