#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public: 
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);

}