#include<bits/stdc++.h>
 
using namespace std ;


// Gives TLE ;
int n ;
int sol(int i ,int k , vector<int>&nums,vector<vector<int>>&dp ) {
    if(k == 0 ) return 0 ;
    if( i >= n) return INT_MAX ;

    if(dp[i][k] != -1 )return dp[i][k] ;

    int take = max(nums[i] , sol(i+2 , k-1 , nums,dp));
    int notTake = sol(i+1 , k , nums,dp) ;

    return dp[i][k] = min(take , notTake) ;
}

bool isPossible(vector<int>&nums , int mid , int k){
    int house = 0 ;
    for(int i= 0 ; i <nums.size() ; i++){
        if(nums[i] <= mid){
            house++ ;
            i++ ;
        }
    }
    return house >= k ;
}

int minCapability(vector<int>& nums, int k) {
    n = nums.size() ; 
    int l = *min_element(nums.begin() , nums.end()) ;
    int r = *max_element(nums.begin() , nums.end()) ;

    int res = r ;

    while(l <= r){
        int mid = (l+r) / 2 ;

        if(isPossible(nums , mid , k)){
            res = mid ;
            r = mid -1 ;
        }
        else{
            l = mid +1 ;
        }
    }
    return res ;
}
 
int main(){
 
    vector<int> nums = {2,7,9,3,1} ;
    int k = 2 ;
    cout << minCapability(nums , k) ;

    return 0;
}