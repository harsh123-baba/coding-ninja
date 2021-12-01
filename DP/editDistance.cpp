#include<iostream>
using namespace std;

int editDistance(string s, string t){
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    }
    if(s[0]==t[0]){
        return editDistance(s.substr(1), t.substr(1));

    }
    else{
        //insert
        int x = editDistance(s.substr(1) , t)+1;

        //remove
        int y = editDistance(s, t.substr(1))+1;

        //update
        int z = editDistance(s.substr(1), t.substr(1))+1;
        return min(x, min(y, z));
    }
}

//  memoization
int editDistanceMem(string s, string t, int **output){
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    } 
    int m = s.size();
    int n = t.size();
    if(output[m][n]!= -1){
        return output[m][n];
    }
    int ans;
    if(s[0] == t[0]){
        ans = editDistanceMem(s.substr(1), t.substr(1), output);
    }
    else{
        int a = editDistanceMem(s.substr(1), t, output)+1; //insert
        int b = editDistanceMem(s.substr(1), t.substr(1), output)+1; //update
        int c = editDistanceMem(s, t.substr(1), output)+1;
        ans = min(a, min(b, c));
    }
    output[m][n] = ans;
    return output[m][n];

}   
int editDistanceMem(string s, string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n];
        for(int j = 0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    return editDistanceMem(s, t, output);
}

//Dp solution


int editDistanceDP(string s, string t){
    int m = s.size();
    int n = t.size();
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    } 
    int **output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
    }
    //first column
    for(int j = 0; j<=n; j++){
        output[0][j] = j;
    }
    //first row
    for(int i = 0; i<=m; i++){
        output[i][0] = i;
    }   

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[m-i]==t[n-j]){
                output[i][j] = output[i-1][j-1];
            }
            else{
                output[i][j] = min(output[i-1][j-1], min(output[i-1][j], output[i][j-1]))+1;
            }
        }
    }
    return output[m][n];
}



int main(){
    string s, t;
    cin>>s>>t;
    cout<<editDistance(s, t)<<endl;
    cout<<editDistanceMem(s, t)<<endl;
    cout<<editDistanceDP(s, t)<<endl;

}