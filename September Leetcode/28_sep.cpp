#include<bits/stdc++.h>
 
using namespace std ;


class MyCircularDeque {
public:
    int size =0 ,front =0, rear = 0;
    vector<int>q ;
    int n ;
    MyCircularDeque(int k) {
        q.resize(k,-1) ;
        n = k ;

    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false ;
        }
        front = (front - 1 + n) % n ;
        q[front] = value ;
        size++ ;
        return true ;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false ;
        }
        q[rear] = value ;
        rear = (rear + 1) % n ;
        size++;
        return true ; 
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false ;
        }
        q[front] = -1;
        front = (front+1) % n ;
        size-- ;
        return true ;

    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false ;
        }
        rear = (rear -1 + n) % n ;
        q[rear] = -1 ;
        size-- ;
        return true ; 
    }
    
    int getFront() {
        
        if(isEmpty()){
            return -1 ;
        }
        return q[front] ;
    }
    
    int getRear() {
        if(isEmpty()){
            return -1 ;
        }
        return q[(rear - 1 + n) % n]; ;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
       return size == q.size() ; 
    }
};
 
int main(){
    int k = 3 ;
    MyCircularDeque* obj = new MyCircularDeque(k);
    vector<string> funcall = {"insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"};
    bool param_1 = obj->insertFront(2);
    
    return 0;
}