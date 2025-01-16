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

Node* convertArrToLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head ;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp ;
        mover = temp ;
    }
    return head ;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next ;
    }
}

Node* Reverse(Node* head){
    Node* curr = head ;
    Node* prev = NULL ;
    Node* Next  = head->next ;

    while(Next != NULL){
        curr->next = prev ;
        prev = curr ;
        curr = Next ;
        Next  = Next ->next ;
    }
    curr->next = prev ;

    return curr ;
}
 
int main(){
 
    vector<int>arr = {1,2,3,4,5,6};
    Node* head = convertArrToLL(arr);
    head = Reverse(head) ;
    print(head);
    return 0;
}