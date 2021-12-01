#include<iostream>
#include<map>
using namespace std;


int main(){
    string s;
    cin>>s;
    map<char, int> m;
    for(int i = 0 ; s[i]!= '\0'; i++){
        m[s[i]]++;
    }
    map<char, int> :: iterator it= m.begin();
    for(it = m.begin(); it!= m.end(); it++){
        cout<<it->first<<"";
    }
    cout<<endl;
}