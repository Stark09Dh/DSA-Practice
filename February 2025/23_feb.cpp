#include<bits/stdc++.h>

// contruct binary tree from PreOrder and Postorder 
 
using namespace std ;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* solve(int preStart , int postStart , int preEnd ,vector<int>& preorder, vector<int>& postorder){
    if(preStart > preEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]) ;
    
    if(preStart == preEnd) return root ;

    int nextNode = preorder[preStart+1] ;

    int j = postStart ;
    while(postorder[j] != nextNode) {
        j++ ;
    }
    int num = j - postStart + 1 ;

    root -> left = solve(preStart+1, postStart , preStart+num , preorder , postorder) ;
    root -> right = solve(preStart+num+1, j+1 , preEnd , preorder , postorder) ;

    return root ;
}


TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size() ;
    return solve(0,0,n-1,preorder , postorder) ;    
}

vector<vector<int>> levelorder(TreeNode* root){
    vector<vector<int>>ans ;
    if(root== NULL) return ans ;
    queue<TreeNode*>q ;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans ;
}
 
int main(){
    vector<int>preorder = {1,2,4,5,3,6,7} ;
    vector<int>postorder = {4,5,2,6,7,3,1} ;

    TreeNode* root = constructFromPrePost(preorder,postorder) ;

    vector<vector<int>>ans = levelorder(root) ;

    for(vector<int>vec : ans){
        for(int i : vec){
            cout << i << " " ;
        }
    }   
    return 0;
}