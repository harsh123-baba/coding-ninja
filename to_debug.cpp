
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
};

TreeNode<int>* ans = NULL;
int sum = 0;
TreeNode<int>* max_sum(TreeNode<int> * root){
    TreeNode<int>* x = root;

    
    
    int xsum = x->data;    

    
    for(int i =0; i<x->children.size(); i++){
        xsum += x->children[i]->data; 
        // cout<<xsum<<endl;   

    }
    cout<<"______________________\n";
    for(int i =0; i<x->children.size();i++){
        if(xsum>::sum){
        ans = x;
        ::sum = xsum; 
    }
        cout<<ans->data<<endl;
        x = max_sum(root->children[i]);
        cout<<x->data<<endl;
    }
    return ans;

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



int main(){

    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);
    TreeNode<int>* child3 = new TreeNode<int>(4);
    TreeNode<int>* tchild1 = new TreeNode<int>(6);
    TreeNode<int>* tchild0 = new TreeNode<int>(5);
    TreeNode<int>* thchild0 = new TreeNode<int>(7);
    TreeNode<int>* thchild1 = new TreeNode<int>(8);
    TreeNode<int>* echild0 = new TreeNode<int>(9);
    
    
    root->children.push_back(child1);
    root->children.push_back(child2);
    
    child1->children.push_back(tchild0);
    child1->children.push_back(tchild1);
    
    child2->children.push_back(thchild0);
    child2->children.push_back(thchild1);
    
    thchild1->children.push_back(echild0);
    

    cout<<endl;
    TreeNode<int>* sum =  max_sum(root);
    PrintLevel(sum);
}