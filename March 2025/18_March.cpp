#include<bits/stdc++.h>
 
using namespace std ;

class Solution{
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 1 ;
        int i = 0 , j = 0 ;
        int mask = 0 ;

        while(j < n){

            while(mask & nums[j] != 0){
                mask = ( mask ^ nums[i] ) ;
                i++ ;
            }
            res = max(res , j-i+1) ;
            mask = (mask | nums[j]) ;
            j++;
        }
        return res ;       
    }
};
 
int main(){
    vector<int> nums = {1,3,8,48,10} ;
    cout << (new Solution) -> longestNiceSubarray(nums) <<endl;
    
    return 0;
}