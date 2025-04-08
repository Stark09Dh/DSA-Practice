#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int n;
    vector<vector<int>> dp ;
    int total_sum ;
    bool sol(int i , int first , vector<int>&nums){
        if (first > total_sum / 2) {
            return false;  
        }
        if(i == n){
            return first == total_sum / 2 ;
        }

        

        if(dp[i][first] != -1){
            return dp[i][first] ;
        }

        bool take_first = sol(i+1 , first + nums[i], nums ) ;
        bool take_second = sol(i+1 , first , nums) ;

        return  dp[i][first] = take_first || take_second ;
    }


    bool canPartition(vector<int>& nums) {
        n = nums.size() ;
        total_sum = accumulate(nums.begin() , nums.end() , 0 );
        if(total_sum % 2 != 0) return false ;
        dp.resize(n+1 , vector<int>(total_sum / 2 + 1 , -1) ) ;
        return sol(0,0, nums) ;
    }
 
};
int main(){
 
    Solution sol ;
    vector<int>nums = {1,5,11,5} ;
    cout << sol.canPartition(nums) ;
    
    return 0;
}