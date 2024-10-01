#include<bits/stdc++.h>
 
using namespace std ;

class CustomStack {
public:
    vector<int>st;
    int n ;
    
    CustomStack(int maxSize) {
        n = maxSize ;
    }
    
    void push(int x) {
        if(st.size() < n){
            st.push_back(x) ;
        }
        
    }
    
    int pop() {
        if(st.size() <= 0){
            return -1 ;
        }
        else{
            int temp = st.back();
            st.pop_back();
            return temp ;
        }
    }
    
    void increment(int k, int val) {
        int size = min(k,(int)st.size());
        for(int i=0;i<size;i++){
            
            st[i] += val ;
            
        }
    }
};
 
int main(){
    int maxSize = 3 ;
    CustomStack* obj = new CustomStack(maxSize);
    obj->push(2);
    int param_2 = obj->pop();
    cout << param_2 ;
    
    return 0;
}