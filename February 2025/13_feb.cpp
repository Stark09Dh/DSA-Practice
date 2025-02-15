#include<bits/stdc++.h>
 
using namespace std ;

int minOperations(vector<int>& nums, int k) {
    int n= nums.size() ;
    priority_queue < int, vector<int>, greater<int> > minH;
    for(auto &i : nums){
        minH.push(i) ;
    }
    int count = 0 ;

    while( minH.top() < k){
        if(minH.size() >= 2){
            int x = minH.top() ;
            minH.pop() ;
            int y = minH.top() ;
            minH.pop() ;
            int val = min(x,y)*2 + max(x,y) ;
            cout << x << " " << y << " " << val  << endl;
            minH.push(val) ;
            count++ ;
        }
    }

    return count ;
}
 
int main(){
 
    vector<int>nums = {1,1,2,4,9};
    int  k = 20 ;
    cout << minOperations(nums , k ) ;
    return 0;
}