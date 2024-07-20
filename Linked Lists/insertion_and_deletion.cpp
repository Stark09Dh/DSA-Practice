#include<bits/stdc++.h>

/*
Deletion 
    | - head
    | - value
    | - position
    | - tail

Insertion
    | - head
    | - value
    | - position
    | - tail
*/
 
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

// Deletion 

Node* deletehead(Node* head){
    if(head == NULL) return head ;
    Node* temp = head ;
    head = head->next ;
    free(temp);
    return head ;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL ;
    Node* temp = head ;
    Node* prev = NULL ;
    while(temp->next->next != NULL){
        temp = temp->next ;
    }
    delete temp->next ;
    temp->next = NULL ;
    return head ; 
}

Node* delete_k(Node* head, int k ){
    if(head == NULL) return NULL;
    if(k==1){
        Node* temp = head ;
        head = head->next;
        free(temp);
        return head ;
    }
    int cnt = 0 ;
    Node* temp = head ;
    Node* prev = NULL;
    while(temp){
        cnt++;
        if(cnt == k){
            prev->next = temp->next ;
            free(temp);
            break ;
        }
        prev = temp ;
        temp = temp->next ;
    }
    return head ;
}

Node* delete_val(Node* head,int val){
    if(head == NULL) return NULL;
    Node* temp = head ;
    Node* prev = NULL;
    while(temp){
        if(temp->data == val){
            prev->next = temp->next ;
            free(temp);
            break;
        }
        prev = temp ;
        temp = temp->next;
    }
    return head ;
}

// Insertion 

Node* inserthead(Node* head,int val){
    Node* temp = new Node(val);
    if(head == NULL) return temp;
    temp->next = head ;
    head = temp ;
    return head ;
}

Node* insertTail(Node* head, int val){
    Node* newNode = new Node(val);
    if(head == NULL) return newNode;
    Node* temp = head ;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = newNode ;
    return head ;
}

Node* insert_pos(Node* head ,int k , int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        if(k==1){
            return newNode ;
        }
        else{
            return NULL ;
        }
    }
    if(k==1){
        newNode->next= head;
        head = newNode ;
        return head ;
    }
    Node* temp = head ;
    int cnt = 0 ;
    while(temp){
        cnt++ ;
        
        if(cnt == k-1){
            newNode->next = temp->next ;
            temp->next = newNode;
            break ;
        }
        temp  = temp->next ;
    }
    return head ;
}

Node* insertBefore(Node* head , int ele, int val){
    Node* newNode = new Node(val);
    if(head == NULL) return NULL;
    if(ele == head->data){
        newNode -> next = head ;
        head = newNode ;
    }
    Node* temp = head ;
    while(temp){
        if(temp->next->data == ele){
            newNode -> next = temp->next;
            temp->next = newNode;
            break; 
        }
        temp = temp ->next ;
    }
    return head ;
}
 
int main(){

    vector<int>arr = {2,4,8,7,9,5};
    Node* head = convertArrToLL(arr);
    head = insertBefore(head,9,14);
    print(head);

    
    return 0;
}

