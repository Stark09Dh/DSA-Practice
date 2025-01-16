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

bool isPalindrome(Node* head) {
    Node* slow = head ;
    Node* fast = head ;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow -> next ;
        fast = (fast->next)->next ;
    } 
    Node* newHead = Reverse(slow->next ) ; 

    Node* first = head ; 
    Node* second = newHead  ;

    while(second != NULL){
        if(first->data != second->data){
            
            return false ;
        }
        first = first ->next ;
        second = second->next ;
    }
    return true ;
}
 

 
int main(){
    vector<int> arr = {1,2,3,3,2,1} ;
    Node* head = convertArrToLL(arr) ;

    cout << isPalindrome(head) ;
    
    return 0;
}