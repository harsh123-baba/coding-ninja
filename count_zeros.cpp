#include<iostream>
using namespace std;

int count_zeros(int n, int count){
    // int count;
    if(n==0){
        return count;
    }
    if(n%10 == 0){
        count++;
        // n = n/10;
    }
    // n= n/10;
    count = count_zeros(n/10, count);
    return count;

}



int main(){
    int n = 2010;
    cout<<count_zeros(n, 0)<<"\n";
}