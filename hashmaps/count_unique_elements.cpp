#include<iostream>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>
#include<string>
using namespace std;



int main(){
    string s;
    
    getline(cin, s);
    string word;
    vector<string> v;
    unordered_map<string, int> seem;
    stringstream iss(s); 
    cout<<&s<<endl;
    cout<<&iss<<endl;
    string x = iss.str();
    // stringstream ss;
    // ss>
    cout<<x<<endl;


    // cout<<&iss+1 - &iss<<endl;

    while(iss>>word){
        if(!seem.count(word)){
            pair<string, int> p(word, 1);
            seem.insert(p);
            
        }   
        else{
            seem[word]++;
        }
    }

    cout<<seem.size()<<endl;
    
}