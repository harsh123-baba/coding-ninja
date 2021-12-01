#include<iostream>
#include "max_heap.h"
// #include "heap.h"
using namespace std;

int main(){
    HeapSort p;
    p.Insert(100);
    p.Insert(101);
    p.Insert(151);
    p.Insert(4);
    p.Insert(17);
    p.Insert(21);
    p.Insert(57);

    cout<<p.size()<<endl;
    cout<<p.getmax()<<endl;
    while(!p.isEmpty()){  
        cout<<p.remove()<<" ";
    }

    cout<<p.size()<<endl;

}