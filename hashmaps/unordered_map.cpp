#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    unordered_map<string, int> ourmap;
    

    // Insert 
        //using pair class
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    //another wat is to save like you did in array

    ourmap["def"] = 2;
    
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("def")<<endl;
    cout<<"Size of "<<ourmap.size()<<endl;

    // cout<<ourmap.at("ghi")<<endl; // then it will throw a error of not able to find key
    cout<<ourmap["ghi"] <<endl; // it will create ghi in ourmap and its key is 0 for now
    cout<<"Size of "<<ourmap.size()<<endl;

    //so what to do if we want to find that element is present or not
    if(ourmap.count("ghi") >0){
        cout<<"ghi is present"<<endl;
    }

    ourmap.erase("ghi");
    cout<<"Size of "<<ourmap.size()<<endl;
if(ourmap.count("ghi") >0){
        cout<<"ghi is present"<<endl;
    }
}