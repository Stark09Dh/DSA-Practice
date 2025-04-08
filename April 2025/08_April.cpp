#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;
        unordered_set<int>seen ;
        for(int i = n-1; i>=0 ; i--){
            if(seen.count(nums[i])){
                ans = (i+3) / 3 ;
                break ;
            }
            seen.insert(nums[i]) ;
        }
        return ans ;
    }
 
};
int main(){
 
    Solution sol ;   //0 1 2 3 4
    vector<int>nums = {1,2,3,4,4} ;
    cout << sol.minimumOperations(nums) ;
    
    return 0;
}