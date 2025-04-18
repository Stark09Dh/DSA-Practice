#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:

    int countPairs(vector<int>& nums, int k) {
        int pairs = 0 ; 
        int n = nums.size() ;
        for(int i =0 ; i< n; i++){
            for(int j = i+1 ; j < n; j++){
                if(nums[i]== nums[j] && i*j % k == 0){
                    pairs++ ;
                }
            }
        }
        return pairs ;   
    }
 
};
int main(){
 
    Solution sol ;
    int k = 2 ;
    vector<int>nums = {3,1,2,2,2,1,3} ;
    cout << sol.countPairs(nums,k) ;
    
    return 0;
}