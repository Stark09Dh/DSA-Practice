#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int ,int> left ;
    
        unordered_map<int ,int> right ;
        for(int i = 0 ; i < n ; i++){
            right[nums[i]]++ ;
        }

        for(int i = 0 ; i  <  n ; i++){
            int num  = nums[i] ;
            left[num]++;
            right[num]-- ;
            int left_len = i+1 ;
            int right_len = n-i-1 ;

            if(2*left[num] > left_len && 2*right[num] > right_len){
                return i ;
            }
        }
        return -1 ;
    }
};
int main(){
    vector<int>nums = {1,2,2,2} ;

    Solution sol ;
    cout << sol.minimumIndex(nums) ;
    
    return 0;
}