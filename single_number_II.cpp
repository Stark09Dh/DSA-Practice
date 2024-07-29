#include<bits/stdc++.h>
 
using namespace std ;


// Brute Force TC = O(n*log(m))+O(m) SC = O(m), m = n/3 + 1
int singleNumber(vector<int>&nums){
    unordered_map<int , int> mp ;
    int n= nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }

    
    for(auto &it : mp){
        if(it.second == 1){
            return it.first ;
        }
    }
    return -1 ;
}

// Better Approach TC = O(nlog(n)) + O(n/3) SC = O(1)

int singleNumber2(vector<int>&nums){
    int n = nums.size();
    for(int i=1 ; i<n;i+=3){
        if(nums[i-1] != nums[i]){
            return  nums[i-1];
        }
    }
    return nums[n-1];
}
 
// Most Optimal Approach 

int singleNumber3(vector<int>&nums){
    int n = nums.size();
    int ones = 0 , twoes = 0 ;
    for(int i=0;i<n;i++){
        ones = (ones ^ nums[i]) & (~twoes) ;
        twoes = (twoes ^ nums[i]) & (~ones) ;
    }
    return ones ;
}


int main(){
 
    vector<int> nums = {5,5,5,2,4,4,4};
    int ans = singleNumber3(nums);
    cout << ans ;
    return 0;
}