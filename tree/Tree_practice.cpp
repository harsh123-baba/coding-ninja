#include<iostream>
#include<bits/stdc++.h>
#include<vector>

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


void Print(TreeNode<int>* root ){
    cout<<root->data<<" : ";
    for(int i = 0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i = 0 ; i<root->children.size(); i++){
        Print(root->children[i]);
    }
}



TreeNode<int>* create(){
    int rootval;
    cout<<"Enter data : ";
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    int n;
    cout<<"Enter number of children of : "<<root->data<<" ";
    cin>>n;
    for(int i = 0; i<n; i++){
        // int childval;
        // cout<<"Enter child value of "<<root->data<<" ";
        // cin>>childval;
        TreeNode<int>* child = create();
        root->children.push_back(child);

    }
    return root;
}


TreeNode<int>* LevelInput(){

    queue<TreeNode<int>*>pendingNodes;
    int rootval;
    cout<<"Enter the root Value : ";
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    pendingNodes.push(root);
    // root->children.push_back(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"Enter the no of children "<<front->data<<" : ";
        cin>>n;
        for(int i = 0; i<n; i++){
            int childval;
            cout<<"Enter "<<i<<"th child value of "<<front->data<<" : ";
            cin>>childval;
            TreeNode<int>* child = new TreeNode<int>(childval);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
    
}


void PrintLevel(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    

    
}




int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* child1 = new TreeNode<int> (2);
    // TreeNode<int>* child2 = new TreeNode<int> (3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    TreeNode<int>* root = LevelInput();
    Print(root);

}