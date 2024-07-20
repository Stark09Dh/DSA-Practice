#include<bits/stdc++.h>
 
using namespace std ;

class Node {
public:
    int data;
    Node* next;
    Node* back ;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

Node* convertToDll(vector<int>&nums){
    int n = nums.size();
    Node* head = new Node(nums[0]);
    Node* prev = head ;
    for(int i=1;i<n;i++){
        Node* temp = new Node(nums[i]);
        temp ->back = prev ;
        prev->next = temp ;
        prev = temp ;
    }
    return head ;

}

void print(Node* head){
    Node* temp = head ;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next ;
    }
}

// Deletion 

Node* deleteHead(Node* head ){
    if(head == NULL || head->next == NULL) return NULL ;

    Node* temp = head ;
    head = head -> next ;
    head -> back = NULL ;
    temp->next = NULL;
    free(temp);
    return head ;
}

Node* deleteTail(Node* head){
    if(head == NULL || head ->next == NULL){
        return NULL ;
    }
    Node* temp = head ;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    Node* prev = temp ->back;
    prev->next = NULL;
    temp -> back = NULL;
    delete temp ;
    return head ;
}

Node* delete_pos(Node* head, int k){
    int cnt = 0 ;
    if(head == NULL) return NULL;
    Node* temp = head;
    while(temp != NULL){
        cnt++ ;
        if(cnt == k) break ;
        temp = temp -> next ;
    }
    Node* prev = temp ->back ;
    Node* front = temp ->next ;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    
    prev->next = front;
    front->back = prev ;
    temp->next = NULL;
    temp ->back = NULL;
    free(temp);
    
    return head ;

}

int main(){
 
    vector<int>nums = {2,4,7,9,3};
    Node* head = convertToDll(nums);
    head = delete_pos(head,2);
    print(head);
    return 0;
}