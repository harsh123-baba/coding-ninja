#include<iostream>
#include<stdio.h>
using namespace std;

int main(){

    int i =10;
    int *p = &i;
    int **p2 = &p;
    cout<<i<<" "<<**p2<<" "<<p<<" "<<*p<<" "<<p2 <<endl;
    cout<<*p2;

}
