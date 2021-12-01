#include<iostream>
#include "trie.h"
using namespace std;


int main(){
    Trie t;
    t.Insert("and");
    t.Insert("are");
    t.Insert("dot");

    cout<<t.search("and")<<endl;
    t.remove("and");
    cout<<t.search("and")<<endl;
    cout<<t.search("are")<<endl;

}