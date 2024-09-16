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
int gcd(int a, int b) 
{ 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
    return result; 
}

Node* vecToll(vector<int>&heads){
    Node* head = new Node(heads[0]);
    Node* mover = head ;

    for(int i=1;i<heads.size();i++){
        Node* temp = new Node(heads[i]);
        mover->next = temp ;
        mover = temp ;
    }
    return head ;
}



Node* insertGreatestCommonDivisors(Node* head) {
    Node* temp = head ;
    while(temp->next != NULL){
        int a = temp->data ;
        int b = temp ->next ->data ;
        int r = gcd(a,b);
        Node* gcdNode = new Node(r);
        gcdNode ->next= temp->next ;
        temp->next = gcdNode ;

        temp = gcdNode->next ;
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
 
    vector<int> arr = {18,6,10,3} ;
    Node* head = vecToll(arr) ;

    head = insertGreatestCommonDivisors(head) ;

    traversalLL(head);

    return 0;
}