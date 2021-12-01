#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool isPresent(vector<int>& a, int key){
    for(int i = 0; i<a.size(); i++){
        if(a[i] == key){
            return true;
        }
    }
    return false;
}


vector<int> intersection(vector<int>& a, int n,vector<int>& b, int m){
    unordered_map<int, int> hash;
    for(int i = 0; i<m; i++){
        hash[a[i]]++;
    }
    for(int i = 0; i<n; i++){
        hash[b[i]]++;
    }
    vector<int> output;
    vector<int>:: iterator ia;
    vector<int>:: iterator ib;
    
    unordered_map<int, int>:: iterator it;
    for(it = hash.begin(); it!=hash.end(); it++){

        if(it->second > 1){
            if(isPresent(a, it->first) && isPresent(b, it->first)){
                output.push_back(it->first);
            }
        }
    }
    return output;
}

int main(){

    // int t;
    // cin>>t;
    // while(t--){
    // vector<int> a;
    // vector<int>b;
    // vector<int> output;

    //     int n;
    //     cin>>n;
    //     for(int i = 0; i<n; i++){
    //         cin>>a[i];
    //     }
    //     int m;
    //     cin>>m;
    //     for(int i = 0; i<m; i++){
    //         cin>>b[i];
    //     }
    //     output = intersection(a, n, b, m);
    //     for(int i = 0; i<output.size(); i++){
    //             cout<<output[i]<<" ";
    //         }
    // }
    vector<int>a;
    a.push_back(2);
    a.push_back(2);
    a.push_back(8);
    a.push_back(5);
    
    vector<int> b;
    b.push_back(3);
    b.push_back(4);
    b.push_back(3);
    b.push_back(7);
    vector<int> output = intersection(a,a.size(), b, b.size());
 
    for(int i = 0; i<output.size(); i++){
        cout<<output[i]<<" ";
    }
}