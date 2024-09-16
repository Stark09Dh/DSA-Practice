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
    for(int i=1 ;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp ;
        mover = temp ;
    }
    return head ;
}

Node* modifiedList(vector<int>& nums, Node* head) {
    unordered_set<int>st(nums.begin(),nums.end());

    while(head != NULL && st.find(head->data) != st.end()){
        Node* temp = head ;
        head = head ->next ;
        delete(temp) ;
    }

    Node* curr = head ;
    while(curr != NULL && curr ->next != NULL){
        if(st.find(curr->next ->data) != st.end()){
           Node* temp = curr -> next ; 
           curr->next = curr ->next ->next ;
           delete(temp );
        }
        else{
            curr = curr->next ;
        }
    }
    return head ;


}
 
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head ->next ;
    }
}

int main(){
 
    vector<int>num = {1,2,3};
    vector<int>arr = {1,2,3,4,5};
    Node* head = vecToll(arr);

    head = modifiedList(num , head);

    print(head);

    return 0;
}