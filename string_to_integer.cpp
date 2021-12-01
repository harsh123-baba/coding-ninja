#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int strtoint(string s){
    if(s.length() == 0){
        return 0;
    }
    int b = strtoint(s.substr(1));
    int a = s[0]-'0';
    a = a*pow(10 , s.length()-1) + b;
    return int(a);
}

int main(){
    string s = "1234";
    cout<<strtoint(s)<<endl;
}