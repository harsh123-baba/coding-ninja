#include<unordered_map>
#include<iostream>
using namespace std;


void makePair(int *a, int size, int x){
    unordered_map<int, int> m;
    for(int i = 0; i<size; i++){
        int key = a[i];
        m[key]++;
    }
    int val = 0;
    for(int i = 0; i < size; i++){
        int key = a[i];
        if(x==0){
            int a = m[key];
            int count = (a*(a-1))/2;
            for(int j = 0; j<count; j++){
                val+=1;
                cout<<key<<" "<<key<<endl;
            }
        }
        else{
            int add = x+a[i];
            int sub = x-a[i];
            int countkey = m[key];
            int counta = m[add];
            int counts = m[sub];
            for(int i =0;i<countkey* counta ; i++){
                val+= 1;
                cout<<min(key , add)<<" "<<max(key, add);
            }
            for(int i =0;i<countkey* counts ; i++){
                val+= 1;
                cout<<min(key , sub)<<" "<<max(key, sub);
            }
        }

        m.erase(key);
    }
    cout<<val<<endl;
}



int main(){
    int n;
    cin>>n;
    int *a;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    makePair(a, n ,x);
    // cout<<"Yha tk chl rha?";
}