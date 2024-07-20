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

void traversalLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next ;
    }
}

int lengthLL(Node* head){
    int len = 0 ;
    Node* temp = head ;
    while(temp){
        len++ ;
        temp = temp->next ;
    }
    return len ;
}

int searchInLL(Node* head,int data){
    Node* temp = head ;
    int idx = -1 ;
    int cnt = 0 ;
    while(temp){
        if(temp->data == data){
            idx = cnt ;
        }
        temp = temp->next ;
        cnt++;
    }
    return idx ;
}
 
int main(){
    vector<int>arr = {2,4,7,3,8};
    Node* head = convertArrToLL(arr);
    traversalLL(head);
    cout << endl ;
    cout << "length of Linked List : "<<lengthLL(head)<<endl;
    cout << "Is 3 available in LL : "<<searchInLL(head,3);
    
    return 0;
}