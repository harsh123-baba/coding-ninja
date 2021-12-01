#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }
};


void Print(TreeNode<int>* root){
    cout<<root->data<<" : ";
    for(int i = 0; i<root->children.size(); i++){
        cout<<root->children[i]->data<<" , ";
    }
    cout<<"\n";
    for(int i =0; i<root->children.size(); i++){
        Print(root->children[i]);
    }
}

TreeNode<int>* create(){
    int rootval;
    cout<<"Enter data : ";
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    int n; 

    cout<<"Enter the number of children of "<<root->data<<" : ";
    cin>>n;
    for(int i =0; i<n; i++){
        TreeNode<int>* child = create();
        root->children.push_back(child);
    }
    return root;
}

//create level

TreeNode<int>* createlevel(){
    int rootval;
    cout<<"Enter data : ";
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        TreeNode<int>*front = pendingnodes.front();
        pendingnodes.pop();
        int n;
        cout<<"Enter the number of children : ";
        cin>>n;
        for(int i =0; i<n; i++){
            int childval;
            cout<<"Enter the "<<i<<"th child value : ";
            cin>>childval;
            TreeNode<int>*child = new TreeNode<int>(childval);
            pendingnodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}


void PrintLevel(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!= 0){
        TreeNode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<" : ";
        for(int i =0; i<front->children.size(); i++){
            cout<<front->children[i]->data<<" , ";
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }
}


TreeNode<int>* maxSum(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    stack<TreeNode<int>*> s;
    q.push(root);
    int large = 0;
    while(!q.empty()){
        int xsum = q.front()->data;
        for(int i =0; i<root->children.size(); i++){
            q.push(root->children[i]);
            xsum += root->children[i]->data;

        }
        if(xsum > large){
            s.push(q.front());
            large = xsum;

        }
        q.pop();
        root = q.front();

    }
    return s.top();

}


TreeNode<int>* max_sum(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    stack<TreeNode<int>*> s;
    q.push(root);
    int large=0;
    while(!q.empty()){
        int x = q.front()->data;
        for(int i = 0; i<root->children.size(); i++){
            q.push(root->children[i]);
            x+=root->children[i]->data;
        }
        if(x>large){
            large = x;
            s.push(q.front());

        }
        q.pop();
        root= q.front();
    }
    return s.top();
}



int height(TreeNode<int>* root) {
    int max = 0;
    for (int i = 0; i < root -> children.size(); i++)
    {
        int test = height(root -> children[i]);
        if(max < test)
        {
            max = test;
        }
    }
    return max + 1;
}

TreeNode<int>* nextLarge(TreeNode<int>* root, int val){
    int diff = INT32_MAX;
    TreeNode<int>* res = root;
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int>* front = q.front();
        q.pop();
        if(front->data - val < diff && front->data>val){
            diff  = front->data - val;
            res = front;
        }
        for(int i =0 ; i<root->children.size(); i++){
            q.push(root->children[i]);
        }

        
    }
    // if(res == NULL){
    //     return NULL;
    // }
    return res;

}

int main(){
    TreeNode<int>* root = createlevel();
    PrintLevel(root);
cout<<"----------------------------------------------\n";
    TreeNode<int>* max = max_sum(root);
    PrintLevel(max);

    cout<<endl;
    cout<<height(root)<<endl;

cout<<"----------------------------------------------\n";
    TreeNode<int>* max1 = nextLarge(root, 4);
    cout<<max1->data;


}