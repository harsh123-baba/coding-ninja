#include<iostream>
using namespace std;




int main(){
    string s;
    // cin>>s;
    // actually cin breaks the input on a space.
    // so we have to take the input in getline function

    getline(cin, s);
    cout<<s<<endl;

    // it can works as array also
    //strings can be modifieable
    //wow!!
    cout<<s.substr(3, 3)<<endl;
    //3rd s dede 3 length ki stringbro
    cout<<s.substr()<<endl; //sbkuch lake de dega
    cout<<s.substr(3)<<endl;
    //3 k baad ka sb lake de dega
    


    //find 
    cout<<s.find("def")<<endl;
    
}