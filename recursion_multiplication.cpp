#include<iostream>
using namespace std;

int max(int &a, int &b){
    return (a>b)?a:b;
}
int multi(int a, int  b){

    if(a==0){
        return 0;
    }
    return b+multi(a-1, b);

}

int main(){
    int a = 10;
    int b = 20;
    cout<<multi(a, b)<<"\n";

}