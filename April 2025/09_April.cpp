#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_set<int> st ;
        sort(nums.begin() , nums.end()) ;
        if( k > nums[0]) return -1 ;
        int minOperation = 0 ; 
        
        for(int i = n-1 ; i >= 0 ; i--){
            if(st.find(nums[i]) == st.end() && nums[i] > k){
                minOperation++ ;
                st.insert(nums[i]);
            }
        }
        return minOperation ;
    }
 
};
int main(){
 
    Solution sol ;
    vector<int> nums = {5,2,4,5,2} ;
    int k = 2 ;
    cout << sol.minOperations(nums, k) ;

    /*
    
    
    
    */
    return 0;
}