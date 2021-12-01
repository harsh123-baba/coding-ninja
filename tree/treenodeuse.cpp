#include<bits/stdc++.h>
#include<iostream>
#include<queue>
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

    ~TreeNode(){
        for(int i =0 ; i<children.size(); i++){
            delete children[i];
        }
    }

};



// TreeNode<int>* Create(){
//     TreeNode<int>* root = new TreeNode(int data);

// }

 
void Print(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    for(int i =0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" , ";
    }
    cout<<endl;
    for(int i = 0; i<root->children.size(); i++){
        Print(root->children[i]);
    }
}

TreeNode<int>* Create(){
    int rootval;
    cout<<"Enter data : ";
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    cout<<"Enter the number of children of "<< rootval<<" ";
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        TreeNode<int>* childNode = Create();
        root->children.push_back(childNode);
    }
    return root;
}

// TreeNode<int>* CreateLevel(){
//     int rootval;
//     cout<<"Enter data ";
//     cin>>rootval;
//     TreeNode<int>* root = new TreeNode<int>(rootval);
//     queue<TreeNode<int>*> pendingNodes;
//     pendingNodes.push(root);
//     while (pendingNodes.size()!=0){
//         TreeNode<int>* front = pendingNodes.front();
//         pendingNodes.pop();

//         int n;
//         cout<<"Enter the number of children : "; 
//         cin>>n;
//         for(int i =0 ; i<n; i++){
//             int childval;
//             cout<<"Enter the "<<i<<"th child value : ";
//             cin>>childval;
//             TreeNode<int>* child = new TreeNode<int>(childval);
//             pendingNodes.push(child);
//             front->children.push_back(child);
//         }



//     }
//     return root;

// }



TreeNode<int>* CreateLevel(){
    cout<<"Enter Data : ";
    int rootval;
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"Enter the no of children for "<<front->data<<" : ";
        cin>>n;
        for(int i = 0; i<n ; i++){
            int childval;
            cout<<"Enter the "<<i<<"th child value ";
            cin>>childval;
            TreeNode<int>* child = new TreeNode<int>(childval);
            pendingNodes.push(child);
            front->children.push_back(child);            
        }
    }
    return root;
}


void PrintLevel(TreeNode<int>* root){
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        cout<<front->data<<" : ";
        pendingNodes.pop();
        for(int i = 0 ; i<front->children.size(); i++){
            cout<<front->children[i]->data<<" , ";
            pendingNodes.push(front->children[i]);
        }
        cout<<"\n";

        
    }
}


int Add(TreeNode<int>*root){
    int sum = root->data;

    for(int i = 0; i<root->children.size(); i++)
    {
        sum+= Add(root->children[i]);

    }
return sum;

}


int numNodes(TreeNode<int>* root){
    int num = 1;
    for(int i =0; i<root->children.size(); i++){
        num += numNodes(root->children[i]);
    }
    return num;
}


void preorder(TreeNode<int>* root){
    cout<<root->data<<" ";
    for(int i = 0; i<root->children.size(); i++){
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root){
    for(int i =0; i<root->children.size(); i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}


// Delete Nodes

// void DeleteAllNodes(TreeNode<int>* root){
//     for(int i =0; i<root->children.size(); i++){
//         root->children[i];
//     }
//     delete root;
// }




int main(){
    // TreeNode<int>*root = new TreeNode<int>(1);
    // TreeNode<int>* child1 = new TreeNode<int>(2);
    // TreeNode<int>* child2 = new TreeNode<int>(3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    TreeNode <int>* root = CreateLevel();
    cout<<endl;
    PrintLevel(root);

    cout<<"_______________________________________________________________\n";    
    cout<<Add(root)<<endl;
    cout<<numNodes(root)<<endl;
cout<<endl;
preorder(root);
cout<<endl;
postorder(root);

    // DeleteAllNodes(root);
    delete root;

}


