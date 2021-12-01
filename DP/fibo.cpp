#include<iostream>
using namespace std;



// Brute force approch O(2^n)
int fibbo(int n){
    if(n<=1){
        return n;
    }
    int a = fibbo(n-1);
    int b = fibbo(n-2);
    return a+b;
}


// Memoization

int fib_helper(int n, int * ans){
    if(n<=1){
        return n;
    }
    if(ans[n]!= -1){
        return ans[n];
    }
    int a = fib_helper(n-1, ans);
    int b = fib_helper(n-2, ans);
    ans[n] = a+b;
    return ans[n];
}

int fibo_2(int n){
    int *ans = new int[n+1];
    for(int i = 0; i<=n; i++){
        ans[i]=-1;
    }
    return fib_helper(n, ans);
}



// Dynamic programing
int fibo_3(int n){
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i<=n; i++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    return ans[n];
}

// space  optimized

int fibo_4(int  n){
    int a = 0;
    int b =1;
    int c;
    for(int i = 2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;

    }
    return c;
}


int main(){
    cout<<fibo_3(6)<<endl;
    cout<<fibo_4(6)<<endl;
    

}