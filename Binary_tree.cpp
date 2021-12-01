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


void Print(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }  // damn base case;
    cout<<root->data<<" : ";
    if(root->left != NULL){
        cout<<"L"<<root->left->data<<" , ";
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    Print(root->left);
    Print(root->right);  
}

BinaryTreeNode<int>* TakeInput(){
    int rootdata;
    cout<<"Enter data ";
    cin>>rootdata;

    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftchlid = TakeInput();
    BinaryTreeNode<int>* rightchild = TakeInput();
    root->left = leftchlid;
    root->right = rightchild;
    return root;
}


BinaryTreeNode<int>* TakeInputLevel(){
    int rootdata;
    cout<<"Enter root value : ";
    cin>>rootdata;
    queue<BinaryTreeNode<int>*> q;
    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    q.push(root);
    while(q.size()!= 0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<"Enter left child of "<<front->data<<" : ";
        int lchildval;
        cin>>lchildval;
        if(lchildval!=-1){
            BinaryTreeNode<int>* lchild =new  BinaryTreeNode<int> (lchildval);
            q.push(lchild);
            front->left = lchild;
        }
        int rchildval;
        cout<<"Enter Right child of "<<front->data<<" : ";
        cin>>rchildval;
        if(rchildval!=-1){
            BinaryTreeNode<int>* rchild = new BinaryTreeNode<int>(rchildval);
            q.push(rchild);
            front->right = rchild;
        }
    }
    return root;
}



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


int count(BinaryTreeNode<int>* root){
    int ans = 1;
    if(root==NULL){
        return 0;
    }
    ans +=count(root->left);
    ans += count(root->right);
    return ans;
}

// is node present

bool isPresent(BinaryTreeNode<int>* root , int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool lserach = isPresent(root->left , x);
    bool rsearch =  isPresent(root->right, x);
    return lserach||rsearch;

}


void Mirror(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    BinaryTreeNode<int>* p;
    Mirror(root->left);
    Mirror(root->right);

    p = root->left;
    root->left = root->right;
    root->right = p;
}


int height(BinaryTreeNode<int>* root){
    // int max;
    if(root==NULL){
        return 0;
    }
    int ldeapth = height(root->left);
    int rdeapth = height(root->right);
    return max(ldeapth , rdeapth)+1;
}


void Preorder(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}


void Postorder(BinaryTreeNode<int>*root){
    if(root == NULL){
        return;

    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}


void Inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}



int main(){
    // BinaryTreeNode <int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);


    // root->right = node2;
    // root->left = node1;

    BinaryTreeNode<int>* root = TakeInputLevel();
    cout<<endl;
    PrintLevel(root);
    cout<<"\n"<<isPresent(root, 3)<<endl;
    // cout<<"\n"<<count(root)<<endl;
    cout<<height(root)<<endl;


    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    Mirror(root);
    PrintLevel(root);
}

