#include<iostream>
#include<queue>
using namespace std;

class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode* TakeInputLevel(){
    int rootval;
    cin>>rootval;
   
    if(rootval==-1){
        return NULL;
    }
    queue<BinaryTreeNode*> q;
    BinaryTreeNode* root = new BinaryTreeNode(rootval);
    q.push(root);
        while(!q.empty()){
            BinaryTreeNode* front = q.front();
            q.pop();
            int leftval;
            cout<<"Enter the left child for "<< front->data<<" ";
            cin>>leftval;
            if(leftval!=-1){
                BinaryTreeNode* lNode = new BinaryTreeNode(leftval);
                front->left = lNode;
                q.push(lNode);
            }
            int rightval;
            cout<<"Enter the right child for "<<front->data<<" ";
            cin>>rightval;
            if(rightval != -1){
                BinaryTreeNode* rNode = new BinaryTreeNode(rightval);
                front->right = rNode;
                q.push(rNode);
            }
        }
    
    return root;
}


void Print(BinaryTreeNode* root){
    queue<BinaryTreeNode*> q;
    q.push(root);
    while( !q.empty()){
        BinaryTreeNode* front = q.front();
        q.pop();
        cout<<front->data<<" : ";
        if(front->left){
            cout<<front->left->data<<" , ";
            BinaryTreeNode* lNode = front->left;
            q.push(front->left);
        }
        if(front->right){
            cout<<front->right->data;
            BinaryTreeNode* rNode = front->right;
            q.push(front->right);
        }
        cout<<endl;
    }
}

int maximum(BinaryTreeNode* root){
    if(root==NULL){
        return INT32_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right))); 
}

int minimum(BinaryTreeNode* root){
    if(root==NULL){
        return INT32_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode* root){
    if(root== NULL){
        return true;
    }
    int  rightmin = minimum(root->right);
    int leftmax = maximum(root->left);
    return (root->data <= rightmin && root->data > leftmax  && isBST(root->left) && isBST(root->right));
}

class bsthelper{
    public:
    int max;
    int min;
    bool isbst;
};


bsthelper isBST2(BinaryTreeNode* root){
    if(root== NULL){
        bsthelper output;
        output.isbst = true;
        output.max = INT32_MIN;
        output.min =INT32_MAX;
        return output;

    }
    bsthelper lchild = isBST2(root->left);
    bsthelper rchild = isBST2(root->right);
    int maximum = max(lchild.max , max(rchild.max, root->data));
    int minimum = min(lchild.min , min(rchild.min, root->data));

    bool isbst = (root->data > lchild.max && root->data <= rchild.min, lchild.isbst &&rchild.isbst);
    bsthelper output;
    output.isbst =isbst;
    output.max = maximum;
    output.min = minimum;
    return output;
}


bool isBST3(BinaryTreeNode* root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data <min && root->data > max){
        return false;
    }
    bool leftChild = isBST3(root->left , min, root->data-1);
    bool rchild = isBST3(root->right, root->data, max);
    return leftChild && rchild;

}



int main(){
    BinaryTreeNode* root = TakeInputLevel();
    cout<<isBST(root)<<endl;
    cout<<isBST3(root, INT32_MIN, INT32_MAX)<<endl;
    Print(root);
}