#include<bits/stdc++.h>
 
using namespace std ;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void getpostOrder(Node* root , vector<int>&ans){
    if(root == NULL) return ;

    for(Node* child : root->children){
        getpostOrder(child,ans);
    } 
    ans.push_back(root->val);
}

vector<int> postorder(Node* root) {
    vector<int>ans ;
    getpostOrder(root,ans);
    return ans ;    
}
 
int main(){
 
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    
    Node* grandchild1 = new Node(5);
    Node* grandchild2 = new Node(6);
    
    // Set up relationships
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    
    child1->children.push_back(grandchild1);
    child2->children.push_back(grandchild2);

    vector<int> ans = postorder(root);

    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}