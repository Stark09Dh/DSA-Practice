#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
private:
    int n;
    int sol(int i , int total , vector<int>&nums){
        if( i == n ) return total ;

        return sol(i+1 , (total ^nums[i]) , nums) + sol(i+1 , total,nums) ;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        n = nums.size() ;

        return sol(0,0,nums) ;
        
    }
 
};
int main(){
 
    Solution sol ;
    vector<int>nums = {5,1,6} ;
    cout << sol.subsetXORSum(nums) ;

    return 0;
}