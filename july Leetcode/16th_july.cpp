#include<bits/stdc++.h>
 
using namespace std ;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right ;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL ;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    if(root == NULL || root->data == p || root->data == q) return root ;

    TreeNode* left = lowestCommonAncestor(root->left , p ,q);
    TreeNode* right = lowestCommonAncestor(root->right , p ,q);

    if(left == NULL) {
        return right ;
    }
    else if(right == NULL){
        return left ;
    }
    else{
        return root ;
    }
}

bool findPath(TreeNode* root , int val , string &path){
    if(root == NULL) return false;

    if(root->data == val) return true ;

    path.push_back('L');
    if(findPath(root->left , val, path)) return true ;

    path.pop_back();

    path.push_back('R');
    if(findPath(root->right , val, path)) return true ;

    path.pop_back();

    return false ;
}



string getDirections(TreeNode* root, int startValue, int destValue){
    TreeNode* LCA = lowestCommonAncestor(root,startValue,destValue);

    string to_start = "";
    string to_des = "";

    findPath(LCA , startValue, to_start);
    findPath(LCA,destValue,to_des);

    string res = "";
    for(int i=0;i<to_start.size();i++){
        res.push_back('U');
    }
    res += to_des ;
    return res ;
}
 
int main(){
 
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);

    int start = 3 , end = 6 ;

    string ans = getDirections(root,start,end);

    cout << ans ;
    return 0;
}

