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

class FindElements {
    public:
    set<int> st ;

    void change(TreeNode* root , int add,int parentData){
        if(root == NULL) return ;
        root->data = 2 * parentData + add ;
        st.insert(root->data) ;
        change(root->left , 1 , root->data) ;
        change(root->right , 2 , root->data) ;
             
    }
    FindElements(TreeNode* root) {
        root->data = 0 ;
        if(root ->left != NULL){
            change(root->left , 1  , 0);
        }
        if( root->right != NULL){
            change(root->right , 2 , 0) ;
        }
    }
    
    bool find(int target) {
        if(st.find(target) != st.end()){
            return true ;
        }
        return false ;
    }
};
 
int main(){
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);
    root->right = new TreeNode(-1);
    root->right->left = new TreeNode(-1);
    root->right->right = new TreeNode(-1);
    
    int target = 7 ;
    FindElements* obj = new FindElements(root);
    bool param_1 = obj->find(target);
    cout << param_1 ;
    
    return 0;
}

/*
       -1                   0
      /   \               /   \
    -1    -1   ---->     1     2
    / \                 / \
   -1  -1              3   4 

*/