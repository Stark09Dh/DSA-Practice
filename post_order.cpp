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
// using Recursion :
void post_order(struct Node* node){
    if(node == NULL) return ;

    post_order(node->left);
    post_order(node->right);
    cout << node->data << " ";
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

    cout << "Using Recursion : ";
    post_order(root);
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