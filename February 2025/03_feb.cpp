#include<bits/stdc++.h>
 
using namespace std ;

int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    int inc = 1 , dec = 1 ; 
    int ans = 0 ;
    // for increasing
    for(int i = 1 ; i < n ; i++){
        if(nums[i] > nums[i-1]){
            inc++ ;
        }
        else inc = 1;
        ans = max(ans , inc) ;
    }  
    // for decreasing
    for(int i = 1 ; i < n ; i++){
        if(nums[i] < nums[i-1]){
            dec++ ;
        }
        else dec = 1;
        ans = max(ans , dec) ;
    } 

    return ans == 0 ? 1 : ans;
}

int main(){
 
    vector<int>nums = {3,3,3,3,3,3} ;
    int ans =  longestMonotonicSubarray(nums) ;
    cout << ans ;

    return 0;
}