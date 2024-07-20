#include<bits/stdc++.h>
 
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

TreeNode* deleteNode(TreeNode* root , unordered_set<int>&st,vector<TreeNode*>&res){
    if(root == NULL) return NULL ;

    root->left = deleteNode(root->left,st,res);
    root->right = deleteNode(root->right,st,res);

    if(st.find(root->data) != st.end()){  // present in to_delete array 
        if(root->left != NULL) res.push_back(root->left);
        if(root->right != NULL) res.push_back(root->right);

        return NULL ;
    }
    else return root ;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
    vector<TreeNode*> res ;
    unordered_set<int>st(to_delete.begin(),to_delete.end());
    
    deleteNode(root,st,res);

    if(st.find(root->data) == st.end()){
        res.push_back(root);
    }

    return res ;

}
 
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> to_delete = {3,5};

    vector<TreeNode*> ans = delNodes(root , to_delete);

    for(auto &it : ans){
        cout << it->data << " ";
    }
    
    
    
    return 0;
}