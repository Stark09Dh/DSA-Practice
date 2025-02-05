#include<bits/stdc++.h>
 
using namespace std ;

int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    int ans = 0 ;
    int sum = nums[0] ; 
    for(int i = 1 ; i < n ; i++){
        if(nums[i] > nums[i-1]){ 
            sum += nums[i] ;
        }
        else if(nums[i] <= nums[i-1]){  
            ans = max(sum , ans) ;
            sum = nums[i] ; 
        }
        ans = max(sum , ans) ; 
    }
    return ans!=0 ? ans : nums[0];
        
}

 
int main(){
 
    vector<int>nums = {100,10,1} ; 
    int ans = maxAscendingSum(nums) ;
    cout << ans ;
    return 0;
}