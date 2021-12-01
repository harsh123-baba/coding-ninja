#include<iostream>
#include<vector>
#include<queue>
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


TreeNode<int>* TakeInput(){
    int rootdata;
    cout<<"Enter data : "<<" ";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter the no of children of "<<rootdata<<" ";
    cin>>n;
    for(int i =0; i<n; i++){
        TreeNode<int>* child = TakeInput();
        root->children.push_back(child);
    }
    return root;

}


void Print(TreeNode<int>* root){
    //it is solved using recursion
    if(root == NULL){
        return;
    }
    cout<<root->data <<" : ";
    for(int i = 0 ; i< root->children.size(); i++){
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i = 0 ; i< root->children.size(); i++){
        Print(root->children[i]);
    }
    

}


TreeNode<int>* TakeInputLevel(){
    int rootdata;
    cout<<"Enter data : ";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){

        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"Enter the number of children of "<<front->data<<" ";
        cin>>n;
        for(int i =0; i<n ; i++){
            int childdata;
            cout<<"Enter the "<<i<<"th element : ";
            cin>>childdata;
            TreeNode<int>* child = new TreeNode<int>(childdata);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;

}

void PrintLevel(TreeNode<int>* root){
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        cout<<front->data<<" ";
        pendingNodes.pop();
        for(int i = 0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<" , ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
    
}




int main(){
    // TreeNode <int>* root = new TreeNode<int>(1);
    // TreeNode<int>* child1 = new TreeNode<int>(2);
    // TreeNode<int>* child2 = new TreeNode<int>(3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    TreeNode<int>* root = TakeInputLevel();
    PrintLevel(root);
}



