#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stack>


bool isBalanced(char s[]){
    stack<char> d;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            d.push(s[i]);
        }
        else if(d.top()=='(' && s[i]==')'){
            d.pop();
        }
        else if(d.top() == '{' && s[i] == '}'){
            d.pop();
        }
        else if(d.top() == '[' && s[i] == ']'){
            d.pop();
        }
        // if(d.empty() && (s[i] == ']' || s[i] == '}' || s[i] == ')')){
        //     return false;
        // }
    }
    if(d.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    char s[] = "[[()]";
    cout<<isBalanced(s)<<endl; 
}