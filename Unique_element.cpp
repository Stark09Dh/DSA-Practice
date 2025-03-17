#include<bits/stdc++.h>
 
using namespace std ;

class Solution{
    public :
    // TC : O(n) , SC : O(n)
    bool unique_element(vector<int>&nums){
        unordered_set<int>st (nums.begin() , nums.end()) ;
        return st.size() == nums.size() ;
    }

    bool unique_element_2(vector<int>&nums){
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] == nums[i-1]){
                return false ;
            }
        }
        return true ;
    }
};
 
int main(){
 
    vector<int> nums = {1,2,3,4,5}  ;// True -> 1 ;
    vector<int>nums2 = {1,2,3,5,1,6,3,6} ;

    cout<< (new Solution) ->unique_element(nums2) <<endl ;
    cout<< (new Solution) ->unique_element_2(nums2) <<endl ;
    
    return 0;
}