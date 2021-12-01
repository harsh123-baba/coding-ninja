#include<iostream>
using namespace std;

inline int max(int& a , int& b){
    return (a>b)?a:b;
}

int main(){
    int a =10;
    int b =12;
    //but in this case my code is mess i have to understand by stop mytself at somepoint to see what the code is doing

    // return (a>b)?a:b;

    // now call the function for better syntex
    // cout<<max(a, b);
//but it is costlier to make call again and again 

    // use inline in function
    // in this case inline take the code of fucntion and paste it here 
    //means cost to take data is gonna 
    cout<<max(a, b)<<endl;


}