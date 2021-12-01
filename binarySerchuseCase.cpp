#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

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

class BST{
    public:
    BinaryTreeNode<int>* root;
        BST(){
            root = NULL;
        }
        // BST(BinaryTreeNode<int>* root){
        // }
        ~BST(){
            delete root;
        }

    private:
    BinaryTreeNode<int>* Insert(int data, BinaryTreeNode<int>* root){
        if(root == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        else if(root->data > data){
            root->left = Insert(data, root->left);

        }
        else{
            root->right = Insert(data, root->right);
        }
        return root;
    }


    public:
    BinaryTreeNode<int>* Insert(int data){
        this->root = Insert(data, this->root);
        return root;
    }

    private:

    BinaryTreeNode<int>* Delete(int data, BinaryTreeNode<int>* root){

        if(root == NULL){
            return NULL;
        }

        if(root->data > data){
            root->left = Delete(data, root->left);
        }

        else if(root->data < data){
            root->right = Delete(data, root->right);
        }

        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left == NULL){
                BinaryTreeNode<int>* temp = root->right;
                root->right = NULL;  // logic behind that is when we call delete root it will delete whole tree so we dont want actually to delete all 
                // we just need to keep temp safe so we keep our root->right in temp 
                delete root;
                return temp;
            }
            else if (root->right== NULL){
                BinaryTreeNode<int>* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }

            else{
                BinaryTreeNode<int>* minNode = root->right;
                while(minNode->left!=NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data= rightMin;
                root->right = Delete(rightMin, root->right);
                return root;
            }
        }
        return root;
    }

    public:
    BinaryTreeNode<int>* Delete(int data){
        this->root = Delete(data, this->root);
        return root;
    }


    private:
    bool hasData(BinaryTreeNode<int>* root , int data){
        if(root == NULL){
            return false;
        }
        if(root->data == data){
            return true;
        }
        else if(root->data > data){
            return hasData(root->left, data);
        }
        else{
            return hasData(root->right, data);
        }
    }

    public:
    bool hasData(int data){
        return hasData(root, data);
    }

};

void Print(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<" : ";
        if(front->left){
            cout<<"L"<<front->left->data<<" , ";
            q.push(front->left);
        }
        if(front->right){
            cout<<"R"<<front->right->data<<" , ";
            q.push(front->right);
        }
        cout<<endl;
    }

}

int main(){

    BST b;
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(4);
    
    // BinaryTreeNode<int>* left = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* right = new BinaryTreeNode<int>(6);
    
    // BinaryTreeNode<int>* lleft = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* lright = new BinaryTreeNode<int>(3);

    // BinaryTreeNode<int>* rleft = new BinaryTreeNode<int>(5);
    // BinaryTreeNode<int>* rright = new BinaryTreeNode<int>(7);
    
    // root->left = left;
    // root->right = right;

    // left->left = lleft;
    // left->right = lright;

    // right->left = rleft;
    // right->right = rright;


    // b.Insert(1);
    // b.Insert(2);
    // b.Insert(3);
    // b.Insert(4);
    // b.Insert(5);
    // b.Insert(6);
    // b.Insert(7);
    // b.Insert(8);

    b.Insert(10);
    b.Insert(5);
    b.Insert(20);
    b.Insert(7);
    b.Insert(3);
    b.Insert(15);
    
    Print(b.root);
    b.Delete(10);
    cout<<"______________________________\n";
    Print(b.root);
    cout<<b.hasData(8)<<endl;
    
} 