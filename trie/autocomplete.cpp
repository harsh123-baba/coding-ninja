#include<iostream>
#include "trie.h"
using namespace std;

void autoComplete(TrieNode * root,string word){
    if(word.size()==0){
        return;
    }

    int index = word[0]-'a';
    TrieNode *child;
    if(root->children[index]!= NULL){
        child = root->children[index];
    }
    else{
        return;
    }

    autoComplete(child, word.substr(1));
    
}


int main(){

}