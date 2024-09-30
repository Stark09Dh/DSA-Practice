#include<bits/stdc++.h>
 
using namespace std ;

class AllOne {
public:
    struct Node{
        int count ;
        list<string>keys;
        Node* prev ;
        Node* next ;
        Node(int c){
            count = c ;
            prev = nullptr ;
            next = nullptr ;
        }
    };

    unordered_map<string , Node*>mp ;
    Node* head ; // head ->next == min key string 
    Node* last ;

    void addNode(Node* prevNode , int count){
        Node* newNode = new Node(count);

        newNode->next = prevNode->next ;
        newNode->prev = prevNode;

        if(newNode->next != NULL){
            newNode->next ->prev = newNode ;
        }
        prevNode->next = newNode ;
        if(prevNode == last){
            last = newNode ;
        }
    }

    void removeNode(Node* node){
        node->prev->next = node->next ;
        if(node->next != NULL){
            node->next->prev = node->prev ;
        }

        if(last == node){
            last = node->prev ;
        }
        delete node ;
    }


    AllOne() {
       head = new Node(0);
       last = head ; 
    }
    
    void inc(string key) {
        if(mp.find(key) == mp.end()){
            // not in map
            if(head->next == nullptr || head->next->count != 1){
                addNode(head ,1);
            }
            head->next ->keys.push_front(key);
            mp[key] = head->next ;
        }
        else{ // string in already in the map
            Node* currNode = mp[key];
            int currCount = currNode->count ;
            if(currNode ->next == nullptr || currNode->next->count != currCount+1){
                addNode(currNode,currCount+1);
            }
            currNode->next->keys.push_front(key);
            mp[key] = currNode->next ;
            currNode->keys.remove(key);
            if(currNode->keys.empty()){
                removeNode(currNode);
            }
        }
    }
    
    void dec(string key) {
        Node* currNode = mp[key] ;
        int currCount = currNode->count ;

        // remove the key if count = 0 ;
        if(currCount ==1){
            mp.erase(key);
        }else{
            if(currNode->prev->count != currCount-1){
                addNode(currNode->prev,currCount-1);
            }
            currNode->prev ->keys.push_front(key);
            mp[key] = currNode->prev ;   
        }
        currNode->keys.remove(key);
        if(currNode->keys.empty()){
            removeNode(currNode);
        }

    }
    
    string getMaxKey() {
       if(last == head ){
        return "" ;
       }
       return last->keys.front();
    }
    
    string getMinKey() {
        if(head->next == nullptr){
            return "";
        }
        return head->next->keys.front();
    }
};
 
int main(){
 
    AllOne* obj = new AllOne();
    obj->inc("hello");
    obj->dec("hello");
    obj->inc("leet");
    string param_3 = obj->getMaxKey();
    string param_4 = obj->getMinKey();

    cout << param_3 << " "<<endl;
    cout << param_4 << " ";
    return 0;
}