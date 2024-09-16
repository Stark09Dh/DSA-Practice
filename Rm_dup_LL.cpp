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

Node* vecToll(vector<int>&arr){
    Node* head = new Node(arr[0]);

    Node* mover = head ;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp ;
        mover = temp ;
    }
    return head ;
}


Node* removeDuplicate(Node* head){

    if(head == NULL) return head ;

    Node* current = head; 

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            
            Node* temp = current->next;
            while (temp != NULL && current->data == temp->data) {
                Node* next = temp->next;
                delete temp; 
                temp = next;
            }
            current->next = temp; 
        } else {
            current = current->next; 
        }
    }
    return head ;
}

void print(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head ->next ;
    }
}
 
int main(){
    vector<int>arr = {1,1,1,1};
    Node* head = vecToll(arr);

    head = removeDuplicate(head) ;
    print(head);

    
    return 0;
}