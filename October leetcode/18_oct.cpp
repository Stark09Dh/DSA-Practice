#include<bits/stdc++.h>
 
using namespace std ;



// Brute Force TC : O(2^n * n)
int calOr(vector<int>&nums){
    int maxor = 0;
    for(int i=0 ;i<nums.size();i++){
        maxor = maxor | nums[i] ;
    }

    return maxor ;
}

int getAllSubsets(vector<int>& nums) {
    int maxor = calOr(nums);
    int ans = 0 ;
    vector<vector<int>> allSubsets;
    int totalSubsets = 1 << nums.size(); // 2^n

    for (int i = 0; i < totalSubsets; ++i) {
        vector<int> subset;
        for (int j = 0; j < nums.size(); ++j) {
            // Check if jth bit is set in i
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        if(calOr(subset) == maxor){
            ans++ ;
        }
    }
    return ans ;
}

int countMaxOrSubsets2(vector<int>& nums) {
    return getAllSubsets(nums) ;
}


// Dynamic PRogramming using memoization
int countSubsets(int i , int currOr ,vector<int>&nums, int maxOr,vector<vector<int>>&dp){
    if(i == nums.size()){
        if(currOr == maxOr){
            return 1 ;
        }
        return 0 ;
    }

    if(dp[i][currOr] != -1) return dp[i][currOr] ;


    int take = countSubsets(i+1 , currOr | nums[i] , nums , maxOr,dp) ;

    int notTake = countSubsets(i+1 ,currOr , nums , maxOr,dp) ;

    return dp[i][currOr] = take + notTake ;

}

int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size() ;
    int maxOr = 0  ;
    for(int &i : nums){
        maxOr |= i ;
    }
    vector<vector<int>>dp(n+1,vector<int>(maxOr+1,-1)) ;
    int currOr = 0 ;

    return countSubsets(0, currOr , nums , maxOr,dp) ;
    
}
 
int main(){
 
    vector<int>nums = {3,2,1,5} ;
    cout << countMaxOrSubsets(nums) ;
    return 0;
}