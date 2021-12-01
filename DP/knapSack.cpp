#include<iostream>
using namespace std;


int knapsack(int *weight, int *value, int n, int w){
    // int n = sizeof(weight)/sizeof(int);
    if( n== 0||w ==0){
        return 0;
    }
    if(weight[0] > w){
        return knapsack(weight+1, value+1, n-1, w);
    }
    int a=0;
    if(weight[0]<=w){
        a = knapSackMem(weight+1, value+1, n-1, w-weight[0])+value[0];
    }
    int b = knapsack(weight+1, value+1,n-1, w);
    return max(a, b);
}
int knapSackMem(int *weight, int *value, int n, int w, int *ans){
    if(n==0 || w==0){
        return 0;
    }
    if(ans[0] != -1){
        return ans[0];
    }
    if(weight[0] > w){
        return knapSackMem(weight+1, value+1, n-1, w, ans);
    }
    int a;
    if(weight[0]<=w){
        a = knapSackMem(weight+1, value+1, n-1, w-weight[0], ans)+value[0];
    }
    
    int b = knapSackMem(weight+1, value+1, n-1, w, ans);
    ans[0] = max(a, b);
    return ans[0];
    
}

// vector s solve krne k case m n to 0 aana hoga see the solution on codestudio

int knapSackMem(int *weight, int *value, int n, int w){
    int *ans = new int[w+1];
    
    for(int i=0; i<=w; i++){
        ans[i]=-1;
    }
    return knapSackMem(weight, value, n, w, ans);
}


// int helper(vector<int> weight, vector<int> value, int n, int maxWeight,int** output )  

// {

// // Write your code here

//    if(n==0 || maxWeight==0){

//        return 0;

//    }

//   if(output[n][maxWeight]!=-1){

    //   return output[n][maxWeight];

//   }

//    int p=helper(weight,value,n-1,maxWeight,output);

//    int q=0;

//    if(weight[n-1]<=maxWeight){

//        q=value[n-1]+helper(weight,value,n-1,maxWeight-weight[n-1],output);

//    }

//    output[n][maxWeight]=max(p,q);

//    return max(p,q);

// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  

// {

// // Write your code here

//    int** output=new int*[n+1];

//    for(int i=0;i<n+1;i++){

//        output[i]=new int[maxWeight+1];

//        for(int j=0;j<maxWeight+1;j++){

//            output[i][j]=-1;

//        }

//    }

//   return helper(weight,value,n,maxWeight,output);

   

// }



int main(){
    int n = 5;
    int weight[] = {5, 1, 8, 9, 2};
    int value[] = {4, 10, 2, 3, 1}; 
    int w = 15;
    cout<<knapsack(weight, value, n, w)<<endl;
    cout<<knapSackMem(weight, value, n, w)<<endl;

}