#include <iostream>
#include <queue>
#include "Binary_search_tree.cpp"
using namespace std;
/*
template <typename T>
class BinarySearchNode
{
public:
    T data;
    BinarySearchNode<T> *left;
    BinarySearchNode<T> *right;

    BinarySearchNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinarySearchNode()
    {
        delete right;
        delete left;
    }
};


/*
void Print(BinarySearchNode<int> *root)
{
    queue<BinarySearchNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinarySearchNode<int> *front = q.front();
        q.pop();
        cout << front->data << " : ";
        if (front->left)
        {
            cout << "L" << front->left->data << " , ";
            q.push(front->left);
        }
        if (front->right)
        {
            cout << "R" << front->right->data << " , ";
            q.push(front->right);
        }
        cout << endl;
    }
}
*/

void DuplicateInsert(BinarySearchNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    DuplicateInsert(root->left);
    DuplicateInsert(root->right);
    BinarySearchNode<int> *temp = root->left;
    BinarySearchNode<int> *newNode = new BinarySearchNode<int>(root->data);
    root->left = newNode;
    newNode->left = temp;
}

// class Pair{
//     public:
//     int val1;
//     int val2;
// };

// Pair pairSum(BinarySearchNode<int>* root, int s){
//     if(root == NULL){
//        Pair p;
//        p.val1 = 0;
//        p.val2 = 0;
//     }

//     if(root->data - s > root->data){
//         //yeh right m jayega
//         BinarySearchNode<int>* temp = root->right;
//     }
//     else if(root->data - s < root->data){
//         // yeh left m jayega
//         BinarySearchNode<int>* temp = root->left;
//     }

// }

// LPA in Binary Tree

// int LPA(BinarySearchNode<int> *root, int n1, int n2)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     if (root->data == n1 || root->data == n2)
//     {
//         return root->data;
//     }

//     int a = LPA(root->left, n1, n2);
//     int b = LPA(root->right, n1, n2);
//     if (a == NULL && b == NULL)
//     {
//         return -1;
//     }
//     // if(a != -1 && b!= -1){
//     //     return root->data;
//     // }
//     // if(a==-1 && b != -1){
//     //     return b;
//     // }
//     // if(b == -1 && a!= -1){
//     //     return a;
//     // }

//     if (a != NULL && b != NULL)
//     {
//         return root->data;
//     }
//     if (a == NULL && b != NULL)
//     {
//         return b;
//     }

//     if (b == NULL && a != NULL)
//     {
//         return a;
//     }

//     if (a && b)
//     {
//         return root->data;
//     }
// }

// int lcaBinaryTree(BinarySearchNode<int> *root, int val1, int val2)
// {

//     if (root == NULL)
//     {
//         return 0;
//     }
//     if (root->data == val1 || root->data == val2)
//     {
//         return root->data;
//     }
//     int lo = lcaBinaryTree(root->left, val1, val2);
//     int ro = lcaBinaryTree(root->right, val1, val2);

//     if (lo == NULL && ro == NULL)
//     {
//         return -1; //-1
//     }
//     if (lo == NULL && ro != NULL)
//     {
//         return ro;
//     }
//     if (lo != NULL && ro == NULL)
//     {
//         return lo;
//     }
//     if (lo != NULL && ro != NULL)
//     {
//         return root->data;
//     }
//     return -1;
// }


int height(BinarySearchNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight)+1;
}

// bool isBST(BinarySearchNode<int>* root , int min= INT32_MIN , int max = INT32_MAX){
//     if(root == NULL){
//         return true;
//     }
//     if(root->data >= max || root->data < min){
//         return false;
//     }
//     bool leftok = isBST(root->left , min, root->data-1);
//     bool rightok = isBST(root->right , root->data , max);
//     return leftok && rightok;
// }

int maxsubtree(BinarySearchNode<int>* root){
    if(isBST3(root)){
        return height(root);
    }
    int leftans = maxsubtree(root->left);
    int rightans = maxsubtree(root->right);
    return max(leftans, rightans);
}


void PrintBSTRootToNode(BinarySearchNode<int>* root, int k, string s){
    if(root == NULL){
        return;
    }
    if(k-root->data > root->data){

    }
    if(k - root->data < root->data){
        
    }
}


int main()
{

    // BinarySearchNode<int> *root = new BinarySearchNode<int>(4);

    // BinarySearchNode<int> *left = new BinarySearchNode<int>(2);
    // BinarySearchNode<int> *right = new BinarySearchNode<int>(6);

    // BinarySearchNode<int> *lleft = new BinarySearchNode<int>(1);
    // BinarySearchNode<int> *lright = new BinarySearchNode<int>(3);

    // BinarySearchNode<int> *rleft = new BinarySearchNode<int>(5);
    // BinarySearchNode<int> *rright = new BinarySearchNode<int>(7);

    // root->left = left;
    // root->right = right;

    // left->left = lleft;
    // left->right = lright;

    // right->left = rleft;
    // right->right = rright;
    // // DuplicateInsert(root);
    // Print(root);
    // // // cout<<LPA(root, 1,3);
    // lcaBinaryTree(root, 10, 20);
    BinarySearchNode<int>* root = TakeInputLevel();
    cout<<endl;
    cout<<maxsubtree(root)<<endl;
}