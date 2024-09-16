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

void postOrder(TreeNode* root , vector<int>&ans){
    if(root == NULL) return ;
    postOrder(root->left,ans);
    postOrder(root->right,ans);
    ans.push_back(root->data);
}


 
int main(){
 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int>ans ;

    postOrder(root,ans);

    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}