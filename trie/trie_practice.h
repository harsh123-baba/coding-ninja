#include<string>
#include<iostream>
#include "trieNodePractice.cpp"
using namespace std;

class Trie{
    private:
    TrieNode * root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }


    void Insert(TrieNode *root ,string word){
        if(word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        Insert(child, word.substr(1));
    }

    bool search(TrieNode* root, string word){
        if(word.size()==0){
            if(root->isTerminal){
                return true;
            }
            else{
                return false;
            }
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=  NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        search(child, word.substr(1));
    }

    void remove(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];

        }
        else{
            return;
        }
        remove(child, word.substr(1));
        
        if(child->isTerminal==false){
            for(int i = 0; i<26;i++){
                if(child->children[i]!= NULL){
                    return;
                }
            }
            delete child;
            root->children[index]= NULL;
        }

    }
    bool search(string word){
        return search(root, word);
    }
    void remove(string word){
        return remove(root, word);
    }

    void Insert(string word){
        return Insert(root, word);
    }

};



