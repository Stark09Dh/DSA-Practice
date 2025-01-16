#include<bits/stdc++.h>
 
using namespace std ;
int waysToSplitArray(vector<int>& nums) {
    int ans = 0 ;
    int n = nums.size();
    vector<int>prefixSum (n , 0) ;
    prefixSum[0] = nums[0] ;
    for(int i=1;i<n;i++){
        prefixSum[i] = prefixSum[i-1] + nums[i] ;
    }

    for(int i = 0 ; i < n-1 ; i++){
        long long leftPart = prefixSum[i] ;
        long long rightPart = prefixSum[n-1] - leftPart;
        if(leftPart >= rightPart){
            ans++;
        }
    }
    return ans ;
        
}
 
int main(){
 
    vector<int>nums = {10,4,-8,7};
    int ans = waysToSplitArray(nums) ;
    cout << ans ;
    return 0;
}