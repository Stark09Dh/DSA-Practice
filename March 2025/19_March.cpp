#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;
        for(int i = 0 ; i < n-2 ; i++){
            if(nums[i] == 0) {
                nums[i] = (nums[i] == 0) ? 1 : 0 ;
                nums[i+1] = (nums[i+1] == 0) ? 1 : 0 ;
                nums[i+2] = (nums[i+2] == 0) ? 1 : 0 ;
                ans += 1 ;
            }
        }  
        if(nums[n-1] == 0 || nums[n-2]== 0) return -1 ; 
        return ans ;
    }
    
 
};

int main(){
 
    Solution sol ;
    vector<int> nums = {0,1,1,1,0,0} ;
    cout << sol.minOperations(nums) ;
    
    return 0;
}