#include<bits/stdc++.h>

// 862. Shortest Subarray with Sum at Least K

// atleast ---->  Sum >= k
 
using namespace std ;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size(); 
    deque<pair<int,int>>dq ;
    long long sum = 0 ;
    long long ans = INT_MAX ;
    for(long long i = 0;i<n;i++){
        sum += nums[i] ;
        if(sum >= k) {
            ans = min(ans , i+1) ;
        }

        pair<long long ,long long>curr = {INT_MIN , INT_MIN} ;
        while(!dq.empty() and (sum - dq.front().second >= k)){
            curr = dq.front() ;
            dq.pop_front() ;
        }

        if(curr.second != INT_MIN){
            ans = min(ans , (i-curr.first));
        }

        while(!dq.empty() and sum <= dq.back().second){
            dq.pop_back() ;
        }

        dq.push_back({i,sum}) ;
    }
    return (ans ==INT_MAX) ? -1 : ans ;
}

 
int main(){
 
    vector<int>nums = {2,-1,1,-1,1,2} ;
    int k = 3 ;
    cout<< shortestSubarray(nums , k) ;
    return 0;
}