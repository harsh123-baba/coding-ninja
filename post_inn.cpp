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


BinaryTreeNode<int>* getTree(vector<int>& inorder, vector<int>& postorder, int iS, int iE, int pS, int pE){
    if(iS>iE){
        return NULL;
    }
    int rootIndex = -1;
    for(int i = iS; i<=iE; i++){
        if(inorder[i]==postorder[pE]){
            rootIndex = i;
            break;
        }
    }

    int rootdata = postorder[pE];

    int liS = iS;
    int liE = rootIndex-1;
    int lpS = pS;
    int lpE = liE-liS+lpS;
    int riS = rootIndex+1;
    int riE = iE;
    int rpS = lpE+1;
    int rpE = pE-1;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    root->left = getTree(inorder, postorder, liS, liE, lpS, lpE);
    root->right = getTree(inorder, postorder, riS, riE, rpS, rpE);

return root;

}
BinaryTreeNode<int>* buildTree(vector<int>& inorder, vector<int>& postorder){
    int iS = 0;
    int iE = inorder.size()-1;
    int pS = 0;
    int pE = postorder.size()-1;

    BinaryTreeNode<int>* root = getTree(inorder, postorder, iS, iE, pS, pE);
    return root;
}



int main(){
    vector<int> inorder = {4,2,5,1,6,3,7};
    vector<int> postorder = {4,5,2,6,7,3,1 };

    BinaryTreeNode<int>* root = buildTree(inorder, postorder);
    PrintLevel(root);
}

