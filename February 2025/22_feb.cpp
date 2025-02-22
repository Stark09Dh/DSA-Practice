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
int getnumber(int i , int j , string &part){
    int num = 0  ;
    while(i < j){
        num = num*10 + (part[i]-'0') ;
        i++ ;
    }
    return num ;
}

TreeNode* recoverFromPreorder(string traversal) {
    int n = traversal.length() ;
    vector<TreeNode*>stack ;
    int i = 0 ;

    while(i<n){
        int dashes =  0; 
        while(traversal[i] == '-'){
            dashes++;
            i++ ;
        }
        
        int j = i ;
        while( j < n && traversal[j] != '-'){
            j++;
        }
        int val = getnumber(i,j,traversal) ;
        TreeNode* node = new TreeNode(val) ;

        while(stack.size() > dashes){
            stack.pop_back() ;
        }
        if(!stack.empty()){
            TreeNode* parent = stack.back() ;
            if(parent->left == NULL) parent->left = node ;
            else parent->right = node ;

        }
        stack.push_back(node) ;
        i = j ;
        
    } 
    
    return stack[0] ;
}
 
int main(){
    string traversal = "1-2--3--4-5--6--7" ;
    TreeNode* root  = recoverFromPreorder(traversal) ;
    vector<vector<int>>ans = levelorder(root) ;
    for(vector<int> vec : ans ){
        for(int i : vec) {
            cout << i << " " ;
        }
    }

    return 0;
}