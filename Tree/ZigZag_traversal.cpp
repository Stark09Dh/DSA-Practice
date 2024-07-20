#include<bits/stdc++.h>
 
using namespace std ;

class Node {
public:
    int data;
    Node* left;
    Node* right ;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL ;
    }
};


vector<vector<int>> levelorder(Node* root){
    vector<vector<int>>ans ;
    if(root== NULL) return ans ;
    queue<Node*>q ;
    q.push(root);
    bool flag = 1 ;
    while(!q.empty()){
        int size = q.size();
        vector<int>level(size);
        
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            int idx = (flag) ? i : (size -1-i);
            level[idx] = temp->data;
            
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        
        }
        flag = !flag ;
        ans.push_back(level);
    }
    return ans ;
}
 
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "Level Order Traversal :" << endl;
    vector<vector<int>>ans  = levelorder(root);
    for(int i = 0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j]<<" ";
        }
        cout << endl ;
    }
    return 0;
}