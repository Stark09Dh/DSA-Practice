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

// DFS traversal 

// Inorder traversal : Left -> Root -> Right

void inOrder(Node* root){
    if(root == NULL) return ;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

// Preorder traversal : Root -> Left -> Right
void preOrder(Node* root){
    if(root == NULL) return ;
    cout << root ->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Postorder traversal : Left -> Right -> Root
void postOrder(Node* root){
    if(root == NULL) return ;
    postOrder(root->left);
    postOrder(root->right);
    cout << root ->data << " ";
}

// BFS - Breadth First Search (Level Order Traversal)
vector<vector<int>> levelorder(Node* root){
    vector<vector<int>>ans ;
    if(root== NULL) return ans ;
    queue<Node*>q ;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node* temp = q.front();
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
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "Inorder Traversal : ";
    inOrder(root);
    cout << endl;
    cout << "Pre Order Traversal : ";
    preOrder(root);
    cout << endl;
    cout << "Post Order Traversal : ";
    postOrder(root);
    cout << endl;

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