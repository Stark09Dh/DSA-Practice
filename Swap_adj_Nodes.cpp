#include<bits/stdc++.h>
 
using namespace std ;

class Node {
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* vecToll(vector<int>&arr ){
    Node* head = new Node(arr[0]);
    Node* mover = head ;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp ;
        mover = temp ;
    }
    return head ;
}

Node* swapPairs(Node* head) {
    if(head == NULL  || head ->next == NULL) return head ;

    Node* temp = head->next ;
    head ->next = swapPairs(head->next->next);

    temp ->next = head;

    return temp ;
}



void print(Node* head){
    while(head != NULL) {
        cout << head ->data << " ";
        head = head ->next ;
    }
}
 
int main(){
    vector<int>arr = {1,2,3,4};
    Node* head = vecToll(arr);
    head = swapPairs(head);
    print(head);
    
    return 0;
}