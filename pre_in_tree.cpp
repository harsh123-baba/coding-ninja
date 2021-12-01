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



// BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
// 	if (inS > inE) {
// 		return NULL;
// 	}

// 	int rootData = pre[preS];
// 	int rootIndex = -1;
// 	for (int i = inS; i <= inE; i++) {
// 		if (in[i] == rootData) {
// 			rootIndex = i;
// 			break;
// 		}
// 	}

// 	int lInS = inS; //left inorder start
// 	int lInE = rootIndex - 1;//left inorder end
// 	int lPreS = preS + 1;//left preorder start
// 	int lPreE = lInE - lInS + lPreS;//left preorder end
// 	int rPreS = lPreE + 1;//right preorder start
// 	int rPreE = preE;//right preorder end
// 	int rInS = rootIndex + 1;//right inorder start
// 	int rInE = inE;//right inorder end
//     cout<<rInE<<endl;
// 	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
// 	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
// 	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
// 	return root;
// }

// BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
//     return buildTreeHelper(inorder,preorder,0,inLength-1,0,preLength-1);
// }






// BinaryTreeNode<int>* getTree(int *pre,int *in,int preS,int preE,int inS,int inE)
// {
//     ///int size=ei_pre-si_pre+1;
//       if(inS>inE) return NULL;

//     int rootIndex=-1;
//     for(int i=inS;i<=inE;i++)
//     {
//         if(in[i]==pre[preS])
//         {
//             rootIndex=i;
//             break;
//         }

//     }
//     int rootData=pre[preS];
//     int lPreS=preS+1;
//     int lInS=inS;
//     int lInE=rootIndex-1;
//     int lPreE=lInE-lInS+lPreS;
//     int rPreS=lPreE+1;
//     int rPreE=preE;
//     int rInS=rootIndex+1;
//     int rInE=inE;

//     BinaryTreeNode<int>* root=new BinaryTreeNode<int> (rootData);
//     root->left=getTree(pre,in,lPreS,lPreE,lInS,lInE);

//     root->right=getTree(pre,in,rPreS,rPreE,rInS,rInE);

//      return root;


// }

// BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
//     // Write your code here
//     int s1,e1,s2,e2;
//     s1=0;s2=0;e1=preLength-1;e2=inLength-1;
//     cout<<"I am in First function: "<<endl;
//     BinaryTreeNode<int>* root = getTree(preorder,inorder,s1,e1,s2,e2);
//     return root; 
// }




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




// The code that worked AF on LEETCODE



// class Solution {
// public:
    
//     TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE){
//           if(inS>inE) return NULL;

//     int rootIndex=-1;
//     for(int i=inS;i<=inE;i++)
//     {
//         if(inorder[i]==preorder[preS])
//         {
//             rootIndex=i;
//             break;
//         }

//     }
//     int rootData=preorder[preS];
//     int lPreS=preS+1;
//     int lInS=inS;
//     int lInE=rootIndex-1;
//     int lPreE=lInE-lInS+lPreS;
//     int rPreS=lPreE+1;
//     int rPreE=preE;
//     int rInS=rootIndex+1;
//     int rInE=inE;

//     TreeNode* root=new TreeNode(rootData);
//     root->left=getTree(preorder,inorder,lPreS,lPreE,lInS,lInE);

//     root->right=getTree(preorder,inorder,rPreS,rPreE,rInS,rInE);

//      return root;
        
//     }
    
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//     int s1,e1,s2,e2;
//     s1=0;
//     s2=0;
//     e1=preorder.size()-1;
//     e2=inorder.size()-1;
        
//     // cout<<"I am in First function: "<<endl;
//     TreeNode* root = getTree(preorder,inorder,s1,e1,s2,e2);
//     return root; 
//     }
// };


BinaryTreeNode<int>* getTree(vector<int>& preorder, vector<int>& inorder, int pres , int pree, int  ins, int ine){
    if(ins>ine){
        return NULL;
    }
    int rootindex = -1;
    for(int i = ins; i<=ine; i++){
        if(inorder[i]==preorder[pres]){
            rootindex = i;
            break;
        }
    }
    int rootdata = preorder[pres];
    int lins = ins;
    int line = rootindex-1;
    int lpres = pres+1;
    int lpree = (line - lins)+lpres;
    
    int rins = rootindex+1;
    int rine = ine;
    int rpres = lpree+1;
    int rpree = pree;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    root->left = getTree(preorder, inorder, lpres, lpree, lins, line);
    root->right = getTree(preorder, inorder, rpres, rpree, rins, rine);
    return root;
}



BinaryTreeNode<int>* buildTree(vector<int>& preorder,  vector<int>& inorder){
    int ins = 0;
    int ine = inorder.size();
    int pres = 0;
    int pree = preorder.size();

    BinaryTreeNode<int>* root =  getTree(preorder, inorder, pres, pree, ins, ine);
    return root;
}





int main(){
    vector<int> preorder = {1, 2, 4, 5, 3, 6,  7}; 
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};

    BinaryTreeNode<int>* root =  buildTree(preorder , inorder);
    PrintLevel(root);

}
