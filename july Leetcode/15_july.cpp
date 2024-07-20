#include<bits/stdc++.h>
 
using namespace std ;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL ;
    }
};


TreeNode* createBinaryTree(vector<vector<int>>& descriptions){
    unordered_map<int,TreeNode*> mp ;
    unordered_set<int> child ;

    for(auto &it : descriptions){
        int parent = it[0];
        int ischild = it[1];
        bool isleft = it[2] ;
        if(mp.find(parent) == mp.end()){
            TreeNode* newParent = new TreeNode(parent);
            mp[parent] = newParent ;
        }
        if(mp.find(ischild) == mp.end()){
            TreeNode* newChild = new TreeNode(ischild);
            mp[ischild] = newChild;
            
        }
        if(isleft){
            mp[parent]->left = mp[ischild];
        }
        else{
            mp[parent]->right = mp[ischild];
        }
        child.insert(ischild);
    }
    TreeNode* root = NULL;
    for(auto &it : mp){
        if(child.find(it.first) == child.end()){
            root = it.second;
            break ;
        }
    }
    return root ;
    
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
 
    vector<vector<int>>descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    TreeNode* root = createBinaryTree(descriptions);
    vector<vector<int>> ans = levelorder(root);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}