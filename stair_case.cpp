#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int staircase(int n){
    if(n==1 || n==0){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return  staircase(n-1)+staircase(n-2)+staircase(n-3);
}

int main(){
    cout<<staircase(3)<<endl;
}