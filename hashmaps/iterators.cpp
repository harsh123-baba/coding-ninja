#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;


int main(){
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;
    ourmap["abc6"] = 7;

    unordered_map<string, int> :: iterator it = ourmap.begin();
    while (it!=ourmap.end())
    {
        cout<<"Key : "<<it->first<<"   value "<<it->second<<endl;
        it++;
    }
    unordered_map<string , int> :: iterator it3 = ourmap.find("abc");
    // cout<<*it3<<endl;
    ourmap.erase(it3);

    it = ourmap.begin();
    while (it!=ourmap.end())
    {
        cout<<"Key : "<<it->first<<"   value "<<it->second<<endl;
        it++;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator it2 = v.begin();
    for(it2 = v.begin(); it2!=v.end(); it2++){
        cout<<*it2<<" ";
    }
    cout<<endl;

}