#include<iostream>
using namespace std;

// void Remove(char s[]){
//     if(s[0]=='\0'){
//         return ;
//     }
//     if(s[0]!='x'){
//         Remove(s+1);
//     }
//     else{
//         int i=1;
//         for(; s[i]!='\0';i++){
//             s[i-1] = s[i];
//         }
//         s[i-1] = s[i];
//         Remove(s);
//     }
// }

void Remove(char s[]){
    if(s[0]=='\0'){
        return;
    }
    if(s[0]!='x'){
        Remove(s+1);
    }
    else{
        int i =1;
        for(; s[i]!='\0'; i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        Remove(s);
    }
}

int length(char str[]){
    if(str[0]=='\0'){
        return 0;
    }
    int smallString = length(str+1);
    return 1+smallString;
}

int main(){
    char s[] = "xHelxlo";
    Remove(s);
    cout<<s<<endl;
}