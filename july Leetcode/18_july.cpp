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

void make_graph(TreeNode* root , TreeNode* prev ,unordered_map<TreeNode*,vector<TreeNode*>>&adj , unordered_set<TreeNode*>&st){
    if(root == NULL) return ;

    if(root->left == NULL && root->right == NULL) st.insert(root);

    if(prev != NULL){
        adj[root].push_back(prev);
        adj[prev].push_back(root);
    }

    make_graph(root->left, root ,adj,st);
    make_graph(root->right, root ,adj,st);
}


int countPairs(TreeNode* root, int distance) {
    unordered_map<TreeNode*,vector<TreeNode*>>adj;
    unordered_set<TreeNode*>st ;

    make_graph(root, NULL,adj,st);

    int count = 0 ; // gud pairs

    for(auto &leaf : st){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>vis ;
        q.push(leaf);
        vis.insert(leaf);
        for(int level =0;level <= distance ; level++){
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr != leaf && st.count(curr)){
                    count++;
                }
                for(auto &ngh : adj[curr]){
                    if(!vis.count(ngh)){
                        q.push(ngh);
                        vis.insert(ngh);
                    }
                }
            }
        }
    }
    return count / 2 ; 
}
 
int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int distance = 3 ;

    int ans = countPairs(root,distance);

    cout << ans ;

    
    return 0;
}