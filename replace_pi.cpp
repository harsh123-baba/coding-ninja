#include<iostream>
using namespace std;

void Replace(char s[]) {
    if(s[0]=='\0'){
        return;
    }
    if(s[0]!='p' && s[1] != 'i'){
        Replace(s+1);
    }
    else{
        int i = 1;
        for(; s[i]!='\0';){
            i++;
        }

        for(; i!=0; i--){
            s[i+2] = s[i];
        }
        s[i]= '3';
        s[i+1] = '.';
        s[i+2] = '1';
        s[i+3] = '4';
        Replace(s);
    }
}


int main (){
    char* x = new char[100];
    cin>>x;
    Replace(x);
    cout<<x<<endl;
}