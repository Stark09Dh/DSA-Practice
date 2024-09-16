#include<bits/stdc++.h>
 
using namespace std ;

long long minCost(vector<long long>& arr) {
        // Your code here
    priority_queue<long long, vector<long long>, greater<long long>>pq ;
    
    long long ans = 0 ;

    for(long long it : arr){
        pq.push(it);
    }
    
    while(pq.size() >1) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        long long combined = first + second ;
        
        pq.push(combined);
        
        ans += combined ;

    }
    
    return ans ;
}
 
int main(){
 
    vector<long long>arr = {4, 3, 2, 6};
    long long ans = minCost(arr);
    cout << ans ; 
    return 0;
}