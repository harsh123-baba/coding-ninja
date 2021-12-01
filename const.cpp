#include<iostream>
using namespace std;
int main(){
    int k=10;
    const int& j = k;
    int const y = 20;
    const int x = 20; //both are same ways to constant any var

    k++;
   //we can not do this beacuse we constant this path

    // we block the path from j side and this path is damn block to change any variable

    //you can change using k and change will reflect in j also

    
    // j++;

    cout<<k<<" "<<j<<endl;
    // int const i=12;
    // int &i2 = i;
    // i2++;        // we can not even do  this error

    //you can do like this 

    int const i2 = 10;
    int const *p = &i2; //pointer type constant integer

    cout<<i2<<"\n"<<*p<<endl;


}