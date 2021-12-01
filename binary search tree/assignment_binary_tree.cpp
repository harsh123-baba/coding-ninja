#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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

template <typename T>
class Node{
    public:
    T data;
    Node *next;
    Node(T x){
        data = x;
        Node * next = NULL;        
    }
};


vector<Node<int>*> LevelWiseLL(BinaryTreeNode<int>* root){
    vector<Node<int>*> v;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    Node<int>* head = NULL;
    while(q.size()!= 0){
        
        BinaryTreeNode<int>* front = q.front();
       
        q.pop();
        if(front!= NULL){

            Node<int>* newNode = new Node<int>(front->data);
            if(head == NULL){
                head = newNode;
            }
            else{
                Node<int>* temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
                // v.push_back(head);
                
            }
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            front = q.front();
        }
        // v.push_back(head);
        if(front==NULL){
            if(q.empty()){
                return v;
            }
            else{
                cout<<"\n";
                // printf("\n");
                q.pop();
                q.push(NULL);
                v.push_back(head);
                head = NULL;
            }
        }

    }
    return v;
}


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


//level order traversal
void LevelOrderTreversal(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()!=0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front == NULL){
            if(q.empty()){
                return;
            }
            else{
                cout<<endl;
                q.push(NULL);
            }

            
        }
        else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}


// void zigzag(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         return;
//     }
//     stack<BinaryTreeNode<int>*>s;
//     queue<BinaryTreeNode<int>*> q;
//     q.push(root);
//     q.push(NULL);
// }


BinaryTreeNode<int>* RemoveLeafNode(BinaryTreeNode<int>* root){
    if(root== NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
    root->left = RemoveLeafNode(root->left);
    root->right = RemoveLeafNode(root->right);

return root;
}
// Sum of nodes

int sum(BinaryTreeNode<int>* root){
    if(root== NULL){
        return 0;
    }
    int ans = root->data;
    ans+=sum(root->left);
    ans+= sum(root->right);
    return ans;
}


//IsBalanced

int height(BinaryTreeNode<int>* root){
    if(root== NULL){
        return 0;
    }
    return( 1 + max(height(root->left), height(root->right)));

}

bool isBalanced(BinaryTreeNode<int>* root){
    if(root== NULL){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh - rh > 1 && rh - lh > 1)
        return false;
    if(abs(lh-rh)<=1 && isBalanced(root->right) && isBalanced(root->left)){
        return true;
    }
    return false;
}



void PrintLL(Node<int>*head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}




int main(){
    BinaryTreeNode<int>* root = TakeInputLevel();
    cout<<endl;
    PrintLevel(root);
    cout<<endl;
    // cout<<sum(root)<<"\n";
    // cout<<isBalanced(root)<<"\n";
    // RemoveLeafNode(root);
    LevelOrderTreversal(root);
    cout<<endl;
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* lchild = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* lchildl = new BinaryTreeNode<int>(4);
    // BinaryTreeNode<int>* lchildr = new BinaryTreeNode<int>(5);
    
    // BinaryTreeNode<int>* rchild= new BinaryTreeNode<int>(3);
    // BinaryTreeNode<int>* rchildl = new BinaryTreeNode<int>(6);
    // BinaryTreeNode<int>* rchildr = new BinaryTreeNode<int>(7);
    // root->left = lchild;
    // root->right = rchild;
    // lchild->right = lchildr;
    // lchild->left = lchildl;

    // rchild->left = rchildl;
    // rchild->right = rchildr;

    // vector<Node<int>*> v = LevelWiseLL(root);
    // for(int i = 0; i<v.size(); i++){
    //     PrintLL(v[i]);
    // }
    // cout<<endl;
}

