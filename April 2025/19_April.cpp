#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        long long pairs = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > upper) continue ;
            long long high = upper - nums[i] ;
            long long low = lower - nums[i] ;

            auto lower_it = lower_bound(nums.begin() + i + 1, nums.end(), low);
            auto upper_it = upper_bound(nums.begin() + i + 1, nums.end(), high);

            pairs += (upper_it - lower_it) ;    

        }
        return pairs ;
         
    }
 
};
int main(){
 
    Solution sol ;
    vector<int> nums ={0,1,7,4,4,5} ;
    int lower = 3 , upper = 6 ;
    cout << sol.countFairPairs(nums , lower , upper) ;
    return 0;
}