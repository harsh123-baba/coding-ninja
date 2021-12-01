#include<iostream>
#include "ourmap.h"
using namespace std;



int main(){
    ourmap<int> m;
    for(int i= 0; i<15;i++){
        char c = '0'+i;
        string key = "abc";
        key = key+c;
        int value = 1+i;
        m.Insert(key, value);
    }
    cout<<m.size()<<endl;
    int x = m.remove("abc0");
    for(int i= 0; i<15;i++){
        char c = '0'+i;
        string key = "abc";
        key = key+c;
        cout<<key <<" "<<m.getValue(key)<<endl;

    }

}