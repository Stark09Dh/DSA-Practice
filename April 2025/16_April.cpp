#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size() ;
        int i = 0 ;
        int j = 0 ; 
        unordered_map<int ,int> mp ;
        long long res = 0 ;
        long long pairs = 0 ;
        
        while(j < n){
            pairs += mp[nums[j]];
            mp[nums[j]]++ ;

            while(pairs == k){
                res += (n-j) ;
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++ ;
            }
            j++ ;
        }
        return res ;
    }
 
};
int main(){
 
    Solution sol ;
    vector<int>nums = {3,1,4,3,2,2,4};
    int k = 2 ;
    cout << sol.countGood(nums , k) ;
    return 0;
}