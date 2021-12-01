#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int check(string s){
    int x;
    if(s[0]=='\0'){
        x =1;
        return x;
    }
    else if(s[0]=='a'){
        if(s.length()>1){
            if(s[1]=='b' && s[2] == 'b'){
                x=1;
                return x;
            }
            else if(s[1]=='a'){
                x=1; 
                return 1;
            }
            else{
                x = 0;
                return x; 
            }
        }
        else{
            x =1;
            return 1;
        }
    }
    else if(s[0]=='b'){
        if(s.length()>1){
            if(s[1]=='b' && s[2] == 'a'){
                x=1;
                return x;
            }
            else if(s[1]=='b' && s[2]=='\0'){
                x=1;
                return x;
            }
            else{
                x = 0;
                return x; 
            }
        }
        else{
            x=0;
            return x;
        }
    }
    return x;
}


int main(){
    string s = "abba";
    if(s[0]=='a'){
        if(check(s)==1){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }
    else{
        cout<<"false"<<endl;
    }
}