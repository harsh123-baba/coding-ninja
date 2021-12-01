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

    ~TreeNode(){
        for(int i =0; i<children.size(); i++){
            delete children[i];
        }
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
        cout<<front->data<<" : ";
        pendingNodes.pop();
        for(int i = 0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<" , ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
    
}

int numNodes(TreeNode<int>* root ){
    int ans = 1;
    for(int i = 0; i<root->children.size(); i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}


int sumNodes(TreeNode<int>* root){
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++){
        sum += sumNodes(root->children[i]);
    }
    return sum;
}


int max = INT32_MIN;
int findMax(TreeNode<int>* root){

    if(root->data > ::max){
        ::max = root->data;
    }
    for(int i =0; i<root->children.size(); i++){
        :: max = findMax(root->children[i]);
    }
    return :: max;
}
 
//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

// findhegiht
int height = 0;
int FindHeight(TreeNode<int>* root){
    int max = 1;
    if(root == NULL){
        return 0;
    }

        max +=FindHeight(root->children[0]);
    return max;
}


// preorder
void Preorder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
        cout<<root->data<<" ";
    for(int i = 0; i<root->children.size(); i++){
        Preorder(root->children[i]);
    }
}



//postorder
void Postorder(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i = 0; i<root->children.size(); i++){
        // val = root->data;
        Postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}
//k level print
void klevelprint(TreeNode<int>* root, int k){
    if(k==0){
        cout<<root->data<<" ";
    }
    for(int i = 0; i<root->children.size(); i++){
        klevelprint(root->children[i], k--);
    }
    
}

// Degree of a node



int main(){
    // TreeNode <int>* root = new TreeNode<int>(1);
    // TreeNode<int>* child1 = new TreeNode<int>(2);
    // TreeNode<int>* child2 = new TreeNode<int>(3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    TreeNode<int>* root = TakeInputLevel();
    cout<<"Maximum is : "<<findMax(root)<<endl;
    cout<<"Number of nodes : "<<numNodes(root)<<endl;
    cout<<"Sum of Nodes : "<<sumNodes(root)<<endl;
    // cout<<"hegiht of tree : "<<FindHeight(root)<<endl;   // wrong output
    Preorder(root);
    cout<<endl;

    Postorder(root);
    cout<<endl;

    klevelprint(root, 2);
cout<<endl;
    PrintLevel(root);
}



