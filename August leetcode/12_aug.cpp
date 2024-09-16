#include<bits/stdc++.h>
 
using namespace std ;
 

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> > pq;
    int kth ;
    KthLargest(int k, vector<int>& nums) {
        kth = k ;
        for(int &num : nums){
            add(num) ;
        }
    }
    
    int add(int val) {
        if(pq.size() < kth){
            pq.push(val);
        }
        else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};