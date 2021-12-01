#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode<T>* right;    // actually Both are correct way to write


    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete right;
        delete left;
    }

};





void PrintLevel(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*>  q;
    q.push(root);
    while(q.size()!= 0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<" : ";
        if(front->left){
            cout<<"L"<<front->left->data<<" ";
            q.push(front->left);
        }
        if(front->right){
            cout<<"R"<<front->right->data<<" ";
            q.push(front->right);
        }
        cout<<endl;
    }
}


BinaryTreeNode<int>* getTree(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE){
    if(inS>inE){
        return NULL;
    }
    int rootindex = -1;
    for(int i = inS; i<=inE; i++){
        if(inorder[i] == preorder[preS]){
            rootindex = i;
            break;
        }
    }
    int rootdata = preorder[preS];
    int linS = inS;
    int linE = rootindex-1;
    int lpreS = preS+1;
    int lpreE = linE-linS+lpreS;

    int rinS = rootindex+1;
    int rinE = inE;
    int rpreS = lpreE+1;
    int rpreE = preE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    root->left = getTree(preorder, inorder, lpreS, lpreE, linS, linE);
    root->right = getTree(preorder, inorder, rpreS, rpreE, rinS, rinE);
return root;
}




BinaryTreeNode<int>* buildTree(vector<int>& preorder, vector<int>& inorder){
    int inS = 0;
    int inE = inorder.size()-1;
    int preS = 0;
    int preE = preorder.size()-1;
    BinaryTreeNode<int>* root = getTree(preorder, inorder, preS, preE, inS, inE);
    return root;
}


int main(){
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder  = {4, 2, 5, 1, 6, 3, 7};
    BinaryTreeNode<int>* root = buildTree(preorder, inorder);
    PrintLevel(root);
}



