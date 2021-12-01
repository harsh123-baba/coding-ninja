#include<iostream>
using namespace std;

// Brute force
int minStep(int n){
    if(n<=1){
        return 0;
    }
    int x = minStep(n-1);
    
    int y = INT32_MAX;
    int z = INT32_MAX;
    if(n%2==0){
        y = minStep(n/2);
    }
    if(n%3==0){
        z = minStep(n/3);
    }
    int ans = min(x, min(y, z))+1;
    return ans;
}

// Memoization
int minStep2(int n, int *ans){
    if(n<=1){
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int x = minStep2(n-1, ans);
    int y = INT32_MAX;
    int z = INT32_MAX;
    if(n%2 == 0){
        y = minStep2(n/2, ans);

    }
    if(n%3==0){
        z = minStep2(n/3, ans);
    }
    ans[n] = 1+min(x, min(y,z));
    return ans[n];
}

int minStep2(int n){
    int *ans = new int[n+1];
    for(int i = 0; i<=n; i++){
        ans[i] = -1;
    }
    return minStep2(n, ans);

}



// Dynamic Solution
int minStep3(int n){
    int *ans = new int[n+1];
    for(int i = 0; i<=n; i++){
        ans[i] = 0;
    }
    ans[1]=1;
    ans[2] =1;
    ans[3] = 1;
    int ans1, ans2, ans3;
    for(int i = 4; i<=n; i++){
        ans1=ans2=ans3 = n;
        ans1 = ans[i-1];
        if(i%2==0){
            ans2 = ans[i/2];
        }
        if(i%3==0){
            ans3 = ans[i/3];
        }
        ans[i] = 1+ min(min(ans1, ans2), ans3);
    }
    return ans[n];
}





int main(){
    cout<<minStep3(7)<<endl;
}