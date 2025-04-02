#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0 ;
        long long res = 0 ;
        long long left = nums[0];
        for(int i = 1 ; i < n ;i++){
            if(nums[i] > left) left = nums[i];
            for(int k = i+1 ; k< n ; k++){
                res = (left - nums[i])*nums[k];
            }

        }
        return res ;
    }
 
};
int main(){
 
    Solution sol ;
    vector<int> nums = {1,2,3,4,5,6};
    cout << sol.maximumTripletValue(nums) ;
    
    return 0;
}