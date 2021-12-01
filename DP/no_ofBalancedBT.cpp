#include<iostream>
#include<math.h>
using namespace std;

int noOfBinaryTree_dp(int h){
    // int n = pow(2, h);
    int *ans = new int[h+1];
    for(int i = 0; i<=h; i++){
        ans[i] = 0;
    }
    int mod = (int)(pow(10, 9))+7;
    ans[0] = 1;
    ans[1] = 1;
    if(ans[h]!= 0){
        return ans[h];
    }
    for(int i=2; i<=h; i++){
        ans[i] = (ans[i-1]*ans[i-1])+(ans[i-1]*ans[i-2])*2;
        int temp1 = (int)(((long)(ans[i-1])*ans[i-1]) %mod);
        int temp2 = (int)(((long)(ans[i-1])*ans[i-2]*2) % mod);
        ans[i] = (temp1+temp2)%mod;

        // ans[i] = ((long)ans[i - 1] * ((2 * (long)ans [i - 2])%mod + ans[i - 1])%mod) % mod;
    }
    return ans[h];
}


// Memoization
int noofBThelper(int h, int *ans){
    if(h<=1){
        return 1;
    }
    if(ans[h] != 0){
        return ans[h];
    }
    int mod = pow(10, 9)+7;
    int x = noofBThelper(h-1, ans);
    int y = noofBThelper(h-2, ans);
    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)% mod);
    ans[h] = (temp1 + temp2)% mod;
    return ans[h]; 
}

int noofBT(int h){
    int *ans = new int[h+1];
    for(int i = 0 ;i<=h; i++){
        ans[i] = 0;
    }
    return noofBThelper(h, ans);
}



// Bruteforce 
int noOfBinaryTree(int h){
    if(h<=1){
        return 1;
    }
    int mod = (int)(pow(10, 9))+7;
    int x = noOfBinaryTree(h-1);
    int y = noOfBinaryTree(h-2);
    
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2*(long)(x)*y) % mod); 
    int ans = (temp1 + temp2) % mod;
    return ans;
}




int main(){
    cout<<noofBT(6)<<endl;
}