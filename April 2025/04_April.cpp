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
 
class Solution{
public:
    #define P pair<TreeNode* , int>

    P findLCA(TreeNode* curr){
        if(curr == NULL) return make_pair(nullptr , 0) ;

        P left = findLCA(curr->left) ;
        P right = findLCA(curr->right) ;

        if(left.second == right.second){
            return make_pair(curr, 1+left.second) ;
        }
        else if(left.second > right.second){
            return make_pair(left.first , 1+ left.second) ;
        }

        return make_pair(right.first , 1+ right.second) ;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        P res = findLCA(root) ;
        return res.first ;
    }
 
};
int main(){
 
    Solution sol ;
    TreeNode* root = new TreeNode(3) ;
    root->left = new TreeNode(5);
    root->right = new TreeNode(1) ;
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right -> left = new TreeNode(5);
    root->left->right -> right = new TreeNode(4);
    root->right = new TreeNode(1) ;

    TreeNode* res = sol.lcaDeepestLeaves(root) ;

    cout << res->data ;
    
    return 0;
}