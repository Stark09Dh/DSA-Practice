#include<bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val ;
        left = right = NULL;
    }
};

void bfs(Node* root){
    if(root == NULL) return ;

    queue<Node*> q ;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        cout << node->data<<" ";
        q.pop();

        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }
}



int main(){
    struct Node *root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root ->left -> left = new Node(4);
    root ->left -> right = new Node(5);
    root ->left -> right -> left = new Node(6);
    root -> right -> left = new Node(7);
    root -> right -> right = new Node(8);
    root -> right -> right -> left = new Node(9);
    root -> right -> right -> right = new Node(10);
    bfs(root);
    return 0 ;
}
/*
     Representation of Binary Tree :
          1
        /   \
       2     3
     /  \   / \
    4   5  7   8
       /      / \
      6      9  10
*/