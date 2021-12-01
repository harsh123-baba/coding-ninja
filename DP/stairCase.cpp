#include<iostream>
using namespace std;

int stairCasehelper(int n, int count){
    if(n<=0){
        return 0;
    }
    int x = 1+stairCasehelper(n-1, count); 
    int y = 0;
    int z = 0;
    if(n-2>=0){
        y = 1+stairCasehelper(n-2, count);
    }
    if(n-3>=0){
        z = 1+stairCasehelper(n-3, count);
    }
    count = x+y+z;
    return count;
}
int stairCase(int n){
    int count = 0;
    return stairCasehelper(n, count);
}


int stairCase1(int n){
    int *ans = new int[n+1];
    for(int i = 0; i<=n; i++){
        ans[i] = 0;
    } 

    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for(int i = 3; i<=n; i++){
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    return ans[n];
}

int main(){
cout<<stairCase(4)<<endl;
}