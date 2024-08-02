#include<bits/stdc++.h>

// 2134. Minimum Swaps to Group All 1's Together II
 
using namespace std ;



int minSwaps(vector<int>&nums){
    int n = nums.size();
    int ans = INT_MAX ;
    int totalones = 0 ;
    for(int i =0;i<n;i++){
        totalones += (nums[i] ==1) ;
    }

    int i=0,j=0;
    int currOne = 0 , maxOne = 0 ;

    while(j<2*n){
        if(nums[j%n] == 1) {
            currOne++;
        }
        if(j-i+1 > totalones){
            currOne -= nums[i%n];
            i++;
        }
        maxOne = max(maxOne,currOne);
        j++;
    }
    return totalones - maxOne ;

}
 
int main(){
 
    vector<int>nums = {0,1,1,1,0,0,1,1,0};
    int ans = minSwaps(nums);
    cout << ans ;
    // int ans = count(0,8,nums);
    // cout << ans ;
    return 0;
}