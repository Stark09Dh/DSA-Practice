#include<bits/stdc++.h>
 
using namespace std ;

int minSubarray(vector<int>& nums, int p) {
    int n = nums.size() ;
    int sum = 0;
    for(int &x : nums){
        sum = (sum + x) % p ;
    }
    
    int target = sum % p ;

    if(target == 0 ){
        return 0 ;
    }
    unordered_map<int ,int>mp ;
    int res = n ;

    int curr = 0 ;
    mp[0] = -1 ;

    for(int j =0; j<n;j++){
        curr =  (curr + nums[j] ) % p ;

        int rem = ( curr - target + p ) % p ;

        if(mp.find(rem) != mp.end()){
            res = min(res , j - mp[rem]) ;
        }

        mp[curr] =j ;
        
    }
    return res == n ? -1 : res ;

}
 
int main(){
 
    vector<int> nums = {3,1,4,2};
    int p = 6 ;
    cout << minSubarray(nums,p);
    return 0;
}