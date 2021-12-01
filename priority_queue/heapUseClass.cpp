#include<iostream>
#include "priorityQueue.h"
// include "heap.h"  // done before for practice
using namespace std;
int main(){
    PriorityQueue p;
    p.Insert(100);
    p.Insert(10);
    p.Insert(15);
    p.Insert(4);
    p.Insert(17);
    p.Insert(21);
    p.Insert(57);

    cout<<p.size()<<endl;
    cout<<p.getMin()<<endl;
    while(!p.isEmpty()){
        cout<<p.remove()<<" ";
    }
    cout<<endl;
    cout<<p.size()<<endl;
     
}
