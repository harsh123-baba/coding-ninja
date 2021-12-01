#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinarySearchNode{
    public:
    T data;
    BinarySearchNode<T>* left;
    BinarySearchNode<T>* right;

    BinarySearchNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinarySearchNode(){
        delete right;
        delete left;
    }    
};


// this is the level wise printing

void Print(BinarySearchNode<int>* root){
    queue<BinarySearchNode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        BinarySearchNode<int>* front = q.front();
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



bool isPresent(BinarySearchNode<int>* root, int x){
    bool lchild = false;
    bool rchild = false;
    if(root== NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    else if(root->data < x){
        rchild = isPresent(root->right , x); 
    }
    else{
        lchild = isPresent(root->left, x);
    }
    return rchild || lchild;
}


// void PrintBWk1k2(BinarySearchNode<int>* root, int k1, int k2){
//     if(root == NULL){
//         return;
//     }
//     if(root->data > k1 && root->data < k2){
//         cout<<root->data<<" " ;
//     }
//     if(root->data> k1){
//         PrintBWk1k2(root->left, k1, k2);
//     }
//     if(root->data<=k2){
//         PrintBWk1k2(root->right, k1, k2);
//     }

// }


void PrintBWk1k2(BinarySearchNode<int>* root, int k1, int k2){
    if(root == NULL){
        return;
    }
    if(root->data>k1 && root->data<k2){
        cout<<root->data<<"\n";
    }

    if(root->data > k1){
        PrintBWk1k2(root->left, k1, k2);
    }
    if(root->data<=k2){
        PrintBWk1k2(root->right, k1, k2);
    }

}


// int maximum(BinarySearchNode<int>* root){
//     if(root == NULL){
//         return INT32_MIN;

//     }
//     return max(root->data, max(maximum(root->left), maximum(root->right)));
// }



// int minimum(BinarySearchNode<int>* root){
//     if(root == NULL){
//         return INT32_MAX;
//     }
//     return min(root->data, min(minimum(root->left), minimum(root->right)));

// }


// bool checkBST(BinarySearchNode<int>* root){
//     if(root==NULL){
//         return true;
//     }
    
//     int leftmax = maximum(root->left);
//     int rightmin = minimum(root->right);

//     bool output = (root->data >leftmax) && (root->data<=rightmin) && checkBST(root->left) && checkBST(root->right);
//     return output;

// }



int maximum(BinarySearchNode<int>* root){
    if(root == NULL){
        return INT32_MIN;
    }
    return max(root->data, max(maximum(root->left) , maximum(root->right)));
}

int minimum(BinarySearchNode<int>* root){
    if(root== NULL){
        return INT32_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinarySearchNode<int>* root){
    if(root==NULL){
        return true;
    }
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);

    return (root->data > leftmax) && (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
}

//isBST is taking O(n^2);

// so lets improve it

class ReturnBST{
    public:
    int maximum;
    int minimum;
    bool bst;

};

ReturnBST isBST2(BinarySearchNode<int>* root){
    if(root == NULL){
        ReturnBST output;
        output.maximum = INT32_MIN;
        output.minimum = INT32_MAX;
        output.bst = true;
        return output;
    }

    ReturnBST lchild =  isBST2(root->left);
    ReturnBST rchild = isBST2(root->right);

    int maximum = max(root->data, (max(lchild.maximum, rchild.maximum)));
    int minimum = min(root->data, (min(lchild.minimum, rchild.minimum)));

    bool isBSTfinal = (root->data > lchild.maximum && root->data <= rchild.minimum && lchild.bst && rchild.bst);

    ReturnBST output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.bst = isBSTfinal;

    return output;
}


bool isBST3(BinarySearchNode<int>* root, int min = INT32_MIN , int max = INT32_MAX){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }


    bool lchild = isBST3(root->left, min, root->data-1);
    bool rchild = isBST3(root->right, root->data, max);
    return lchild && rchild;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 - 1


BinarySearchNode<int>* makeBST(int a[], int l , int h){
    
    int mid = (l+h)/2;
    BinarySearchNode<int>* root = new BinarySearchNode<int>(a[mid]);
    if(l<h)
    {
        root->left = makeBST(a, l, mid-1);
        root->right = makeBST(a, mid+1, h);
    }
    return root;
}

// from bst to a sorted vector
// lets try inorder method
void sortedFromBST(BinarySearchNode<int>* root){
    if(root == NULL){
        return;
    }

    sortedFromBST(root->left);
    cout<<root->data<<" ";
    sortedFromBST(root->right);
}

//in linked list too

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};


Node* head = NULL;
Node* tail = NULL;
Node* BSTtoLL(BinarySearchNode<int>* root){

    if(root==NULL){
        return NULL;
    }
    Node* lchild = BSTtoLL(root->left);
    Node* newNode = new Node(root->data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    Node* rchild = BSTtoLL(root->right);
    return head;
}

void PrintLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}


//get node to root path

vector<int>* rootToNode(BinarySearchNode<int>* root,int data){
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == data){ 
        
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* lchild = rootToNode(root->left, data);
    if(lchild ){
        lchild->push_back(root->data);
        return lchild;
    } 
    vector<int>* rchild = rootToNode(root->right, data);
    if(rchild) {
        rchild->push_back(root->data);
        return rchild;
    }
    return NULL;
}


BinarySearchNode<int>* TakeInputLevel(){
    int rootdata;
    cout<<"Enter root value : ";
    cin>>rootdata;
    queue<BinarySearchNode<int>*> q;
    if(rootdata == -1){
        return NULL;
    }
    BinarySearchNode<int>* root = new BinarySearchNode<int>(rootdata);
    q.push(root);
    while(q.size()!= 0){
        BinarySearchNode<int>* front = q.front();
        q.pop();
        cout<<"Enter left child of "<<front->data<<" : ";
        int lchildval;
        cin>>lchildval;
        if(lchildval!=-1){
            BinarySearchNode<int>* lchild =new  BinarySearchNode<int> (lchildval);
            q.push(lchild);
            front->left = lchild;
        }
        int rchildval;
        cout<<"Enter Right child of "<<front->data<<" : ";
        cin>>rchildval;
        if(rchildval!=-1){
            BinarySearchNode<int>* rchild = new BinarySearchNode<int>(rchildval);
            q.push(rchild);
            front->right = rchild;
        }
    }
    return root;
}



/*
int main(){

    // BinarySearchNode<int>* root = new BinarySearchNode<int>(4);
    
    // BinarySearchNode<int>* left = new BinarySearchNode<int>(2);
    // BinarySearchNode<int>* right = new BinarySearchNode<int>(6);
    
    // BinarySearchNode<int>* lleft = new BinarySearchNode<int>(1);
    // BinarySearchNode<int>* lright = new BinarySearchNode<int>(3);

    // BinarySearchNode<int>* rleft = new BinarySearchNode<int>(5);
    // BinarySearchNode<int>* rright = new BinarySearchNode<int>(7);
    
    // root->left = left;
    // root->right = right;

    // left->left = lleft;
    // left->right = lright;

    // right->left = rleft;
    // right->right = rright;
    
    // Print(root);
    // // cout<<endl;
    // cout<<isPresent(root, 3)<<endl;
    // PrintBWk1k2(root, 1, 4);
    // cout<<endl;
    // // cout<<minimum(root)<<" "<<maximum(root)<<endl;
    // // cout<<isBST(root)<<endl; 
    // // ReturnBST output = isBST2(root);
    // // cout<<output.bst<<endl;

    // cout<<isBST3(root)<<endl;

    
    int A[] = {-10,-3,0,5,9};
    BinarySearchNode<int>* root = makeBST(A, 0, 6);
    Print(root);
    // sortedFromBST(root);
    // cout<<endl;
    // Node* head = BSTtoLL(root);
    // PrintLL(head);
    // cout<<endl;
    // vector<int>* v = rootToNode(root, 7);
    // for(int i =0; i<v->size(); i++){
    //     cout<<v->at(i)<<" ";
    // }
    // BinarySearchNode<int>* root = TakeInputLevel();
    // Print(root);
    // cout<<isBST3(root);
}
*/