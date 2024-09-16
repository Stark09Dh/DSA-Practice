
#include<bits/stdc++.h>
 
using namespace std ;

int longestSubarray(vector<int>& nums) {
    auto maxVal = max_element(nums.begin(),nums.end());
    int maxV = *maxVal ;
    int cnt = 0 ;
    int maxL = 0 ;

    for(int &num : nums){
        if(num == maxV){
            cnt++ ;
            maxL = max(maxL,cnt);
        }
        else{
            cnt  =  0 ;
        }
    }
    return maxL ;
}
 
int main(){
 
    vector<int>nums = {1,2,3,4} ;
    int ans = longestSubarray(nums);
    cout << ans ;
    return 0;
}