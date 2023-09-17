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
void pre_order(struct Node* node){
    if(node == NULL) return ;

    cout << node->data << " ";
    pre_order(node->left);
    pre_order(node->right);
}
// using Iterative approach : 
void pre(struct Node* root){
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout << root -> data << " ";
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
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

    cout << "Using Recursion : ";
    pre_order(root);
    cout <<endl;
    cout << "Using iterative approach : ";
    pre(root);
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