#include<iostream>
using namespace std;

int power(int x , int n){
    if(n==0 || x==0 ){
        return 1;
    }
    if(n==1){
        return x;
    }
    return x *power(x, n-1);
}


int geometric_sum(int a, int r,int n ,int sum){
    
    if(n==0){
        return a+sum;
    }
    sum = sum+ a*power(r, n);
    return geometric_sum(a, r, n-1, sum);
    // return sum;    
}


int main(){
    cout<<geometric_sum(2, 2, 1, 0);

}