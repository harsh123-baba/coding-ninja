#include<iostream>
using namespace std;
int main(){
    // int i =10;
    // int j=i;
//Use of refrence variable

    int i =10;
    int& j = i;
        //we have common address to reach at 2 places first at i and j as well
    i++;
    cout<<i<<endl;
    cout<<j<<endl;

// what if i copy somthing in j 
int k =100;
j =k;
cout<<i<<endl;
cout<<j<<endl;

}

