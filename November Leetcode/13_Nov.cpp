#include<bits/stdc++.h>
 
using namespace std ;

int binary_Search(vector<int>&nums,int low , int high , int val){
    while(low <= high) {
        int mid = low + (high - low )/ 2 ;
        if( nums[mid] >= val){
            high = mid -1 ;
        }
        else{
            low = mid + 1;
        }
    }
    return high ;
}

long long countFairPairs(vector<int>& nums, int lower, int upper) {
   int n = nums.size(); 
   sort(nums.begin() , nums.end()) ;
   int ans = 0 ;

   for(int i=0;i<n;i++){
        int lowTarget = lower - nums[i] ;
        int highTarget = upper - nums[i] ;
        int lowVal = binary_Search(nums,i+1 , n , lowTarget) ;
        int highVal = binary_Search(nums,i+1 , n , highTarget+1) ;
        ans +=  (highVal-lowVal) ;
   }

   return ans ;

}

// Brute Force TC : O(n*n) ;
long long countFairPairs2(vector<int>& nums, int lower, int upper) {
    int n = nums.size() ;
    long long ans = 0; 
    for(int i = 0;i<n;i++){
        for(int j= i+1 ;j<n;j++){
            if(lower <= nums[i]+ nums[j] && upper >= nums[i]+nums[j]){
                ans +=1 ;
            }
        }
    }
    
    return ans ;
}

 
int main(){
 
    vector<int>nums = {0,1,7,4,4,5} ;
    int lower = 3 , upper = 6 ;
    cout << countFairPairs(nums , lower , upper) ;

    return 0;
}