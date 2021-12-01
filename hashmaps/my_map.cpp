#include<iostream>
#include "my_map.h"

using namespace std;
int main(){
    ourmap<int> map;
    for(int i = 0; i<10; i++){
        char c = '0'+i;
        string key = "abc";
        key = key+c;
        int value = 1+i;
        map.Insert(key, value);
        cout<<map.getloadFactor()<<endl;
    }
    cout<<map.size()<<endl;

    int x = map.remove("abc2");
    int w = map.remove("abc3");
    cout<<x<<endl;

    for(int i = 0; i<10; i++){
        char c = '0'+i;
        string key = "abc";
        key = key+c;
        cout<<key<<" "<<map.getValue(key)<<endl;
    }
    cout<<map.size()<<endl;
    cout<<map.bucketSize()<<endl;
}