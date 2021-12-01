
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


int numNodes(TreeNode<int>* root){
    int num = 1;
    for(int i =0; i<root->children.size(); i++){
        num += numNodes(root->children[i]);
    }
    return num;
}


int Add(TreeNode<int>* root){
    int sum = root->data;
    for(int i =0; i<root->children.size(); i++){
        sum+=Add(root->children[i]);
    }
    return sum;
}

int max = INT32_MIN;
int findMax(TreeNode<int>* root){
    for(int i = 0; i<root->children.size(); i++){
        if(root->children[i]->data > ::max){
            ::max = root->children[i]->data;

        }
    }
    return ::max;
}


void preorder(TreeNode<int>* root){
    cout<<root->data<<" ";
    for(int i =0; i<root->children.size(); i++){
        preorder(root->children[i]);
    }

}
void postorder(TreeNode<int>* root){
    for(int i =0;i<root->children.size(); i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

// int ans=0;
// int max_sum(TreeNode<int>* root){
//     int max = root->data;
//     for(int i =0; i<root->children.size(); i++){
//         max += root->children[i]->data;    
//     }
//     cout<<max<<" ";
//     if(max>::ans){
//         ans = max;
//         cout<<ans<<endl;
//     }
//     for(int i =0; i<root->children.size(); i++){
//         max_sum(root->children[i]);
//     }
// return ans;
// }

// TreeNode<int>* ans = NULL;
// int sum = 0;
// TreeNode<int>* max_sum(TreeNode<int> * root){
//     TreeNode<int>* x = root; 
//     int xsum = x->data;
//     for(int i =0; i<x->children.size(); i++){
//         xsum += x->children[i]->data; 
//         x = max_sum(x->children[i]);
//     }
//     if(sum>xsum){
//         sum = xsum; 
//         ans = x;
//     }
//     return ans;
// }


// void max_sum(TreeNode<int>* root, TreeNode<int>* resNode, int max){
//     if(root== NULL){
//         return ;
//     }
//     int curr = root->data;
//     for(int i = 0 ; i<root->children.size(); i++){
//         curr += root->children[i]->data;
//         max_sum(root->children[i], resNode, max);

//     }
//     if(curr > max){
//         resNode = root;
//         max = curr;
//     }
//     // cout<<resNode->data;
//     return;

// }



void maxSumUtil(TreeNode<int>* root, TreeNode<int>* resNode, int* maxsum)
{
    // Base Case
    if (root == NULL)
        return;
 
    // curr contains the sum of the root and
    // its children
    int currsum = root->data;
 
    // total no of children
    int count = root->children.size();
 
    // for every child call recursively
    for (int i = 0; i < count; i++) {
        currsum += root->children[i]->data;
        maxSumUtil(root->children[i], resNode, maxsum);
    }
 
    // if curr is greater than sum, update it
    if (currsum > *maxsum) {
 
        // resultant node
        resNode = root;
        *maxsum = currsum;
    }
    return;
}
 
// Function to find the node having max sum of
// children and node
TreeNode<int>* maxSum(TreeNode<int>* root)
{
    // resultant node with max sum of children
    // and node
    TreeNode<int>* resNode;
 
    // sum of node and its children
    int maxsum = 0;
 
    maxSumUtil(root, resNode, &maxsum);
 
    // return the key of resultant node
    return resNode;
}















// some question that are really damn fucker right now
 // height of a tree
 // max sum of nodes
 // next large in tree

// int sol;
// int NextLarge(TreeNode<int>* root , int val){
//     for(int i = 0; i<root->children.size(); i++){
//         if(root->data > val && sol > root->data){
//             sol = root->data;
//         }
//             NextLarge(root->children[i], val);   
//     }
// return sol;
// }



// int h = 0;

// int height(TreeNode<int>* root){
//     int sum = 0;
//     for(int i =0; i<root->children.size(); i++){
        
//     }

// }


// int max_sum(TreeNode<int>* root){
//     // ::ans = root->data;
//     int sum = root->data;
//     int xsum = root->data;
//     TreeNode<int>*ans = root;
//     TreeNode<int>* x = root;

//     for(int i =0; i<root->children.size(); i++){
//         xsum += root->children[i]->data;    
//     }
//     if(xsum>sum){
//         ::ans = xsum;
//         x = root;
//     }
//     for(int i =0; i<root->children.size();i++){
//         root->data = max_sum(root->children[i]);
//     }
//     return x->data;
// }







int main(){

    TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* child1 = new TreeNode<int>(2);
    // TreeNode<int>* child2 = new TreeNode<int>(3);

    // root->children.push_back(child1);
    // root->children.push_back(child2);

    // cout<<"____________________________________________________";
    // cout<<endl;
    // cout<<Add(root)<<endl;
    // cout<<numNodes(root)<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // cout<<max_sum(root)<<endl;
    // cout<<endl;
    // TreeNode<int>* sum =  max_sum(root);
    // PrintLevel(sum);

    // cout<<NextLarge(root, 8)<<endl;
    TreeNode<int>* res ;
    res = maxSum(root);
    cout<<endl;
    PrintLevel(res);

}
