#include<iostream>
using namespace std;
int main(){
    int i = 10;
    int j = 20;
    int const *p = &i;   //  p is saying i m pointing towards a constant
        //p can be change but value of *p cant be
    // (*p)++; //illegal

    cout<<p<<" " <<*p<<endl;
    p = &j;
    cout<<p<<" "<<j<<" "<<*p<< " "<<i<<endl;

    // but what if i want to make constant our p value also constant

    int i1=10;
    int j1 = 20;
    int * const l = &i;
    cout<<l<<endl<<i1<<endl<<j1<<endl<<*l<<endl;


    // l = &j;    //illegal
    (*l)++; 
    cout<<l<<endl<<i1<<endl<<j1<<endl<<*l<<endl;



}