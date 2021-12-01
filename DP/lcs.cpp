#include<iostream>
#include<string>
using namespace std;

int lcs(string s, string t){
    if(s.size() == 0 || t.size()==0){
        return 0;
    }
    if(s[0] == t[0]){
        return 1+ lcs(s.substr(1), t.substr(1));
    }
    else{
        int a = lcs(s.substr(1), t);
        int b = lcs(s.substr(1), t.substr(1));
        int c = lcs(s, t.substr(1));
        return max(a, max(b, c));
    }
}

// memoization
int lcsMem(string s, string t, int **output){
    int m = s.size();
    int n = t.size();
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    if(output[m][n] != -1){
        return output[m][n];
    }
    int ans;
    if(s[0] == t[0]){
        ans = 1+ lcsMem(s.substr(1), t.substr(1), output); 
    }
    else{
        int a = lcsMem(s.substr(1), t, output);
        int b = lcsMem(s.substr(1), t.substr(1), output);
        int c = lcsMem(s, t.substr(1), output);
        ans = max(a, max(b, c));
    }
    output[m][n] = ans;
    return output[m][n];
}

int lcsMem(string s , string t){
    int m = s.size();
    int n = t.size();
    int **output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j =0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    
    return lcsMem(s, t, output);
}


// Dynamic Programming 
int lcsDP(string s, string t){
    int m =s.size();
    int n = t.size();
    int ** output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j = 0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    // output[0][0] = 0;
    for(int j = 0; j<=n; j++){
        output[0][j] = 0;
    }
    for(int i = 1; i<=m; i++){
        output[i][0] = 0;
    }
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[i] == t[j]){
                output[i][j] = 1+output[i-1][j-1];
            }
            else{
                output[i][j] = max(output[i-1][j-1], max(output[i-1][j], output[i][j-1]));
            }
        }
    }
    return output[m][n];
}



int main(){
    string s, t;
    cin>>s;
    cin>>t;
    // cin>> s>>t;
    cout<<lcsMem(s, t)<<endl;
    cout<<lcs(s, t)<<endl;
    cout<<lcsDP(s, t)<<endl;
}