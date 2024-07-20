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


Node* findMiddle(Node* head){
    Node* slow = head ;
    Node* fast = head->next ;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next ;
        slow = slow->next ;
    }
    return slow ;
}

Node* mergeTwoList(Node* list1, Node* list2){
    Node* dmmy = new Node(1);
    Node* temp = dmmy ;
    while(list1!= NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1 ;
            temp = list1 ;
            list1 = list1->next ;
        }
        else{
            temp->next = list2;
            temp = list2 ;
            list2 = list2->next ;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2 ;

    return dmmy->next ;
}


Node* sortLL(Node* head){
    if(head == NULL || head->next == NULL) return head ;

    Node* middle = findMiddle(head);
    Node* right = middle->next ;
    middle->next = NULL ;
    Node* left = head ;

    left = sortLL(left);
    right = sortLL(right) ;

    mergeTwoList(left,right);


}
 
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

void traversalLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next ;
    }
}

int main(){
 
    vector<int>arr = {4,2,1,3};
    Node* head = convertArrToLL(arr);
    traversalLL(head);

    cout << endl ;

    cout << "After sorting : " ;

    head  = sortLL(head) ;

    traversalLL(head) ;
    
    return 0;
}