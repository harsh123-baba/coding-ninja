#include<iostream>
using namespace std;

int lcsBruteForce(string s, string t){
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    if(s[0] == t[0]){
        return 1+ lcsBruteForce(s.substr(1), t.substr(1));
    }
    else{
        int a = lcsBruteForce(s.substr(1), t);
        int b = lcsBruteForce(s.substr(1), t.substr(1));
        int c = lcsBruteForce(s, t.substr(1));
        int ans = max(a, max(b, c));
        return ans;
    }
    
}


int lcsMem(string s, string t, int** output){
    if(s.size()==0 ||t.size()==0){
        return 0;
    }
    int m = s.size();
    int n = t.size();
    if(output[m][n]!=-1){
        return output[m][n];
    }
    if(s[0] == t[0]){
        return 1+lcsMem(s.substr(1), t.substr(1), output);
    }
    else{
        int a = lcsMem(s.substr(1), t, output);
        int b = lcsMem(s.substr(1), t.substr(1), output);
        int c = lcsMem(s, t.substr(1), output);
        output[m][n] = max(a, max(b, c));
        return output[m][n];
    }
}
int lcsMem(string s, string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j = 0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    return lcsMem(s, t, output);
}





int main(){
    string s, t;
    cin>>s>>t;
    cout<<lcsMem(s, t)<<endl;
    cout<<lcsBruteForce(s, t)<<endl;
}