#include<bits/stdc++.h>
 
using namespace std ;

// TC : O(n) -- Easy
int maximumCount(vector<int>&nums){
    int n = nums.size() ;
    int pos = 0, neg = 0;
    for(int i : nums){
        if(i < 0) neg++ ;
        if(i >0 ) pos++;
    }
    return max(pos ,neg) ;
}

// TC : O(log(n)) -- Medium
int binaryMaximumCount(vector<int>&nums){
    int n = nums.size() ;
    int l = 0 , h = n-1 ;
    int first_0 = n ,count_0 = 0 ;
    
    // find first 0 ;
    while( l <= h){
        int mid = (l+h)/2 ;
        if( nums[mid] >= 0){
            first_0 = mid ;
            h = mid -1 ;
        }
        else{
            l = mid + 1 ;
        }
    }
    l = first_0 , h = n-1 ;
    int firstPositive = n ;
    while( l <= h){
        int mid = (l+h) / 2  ;
        if(nums[mid] > 0){
            firstPositive = mid ;
            h = mid - 1 ;
        }
        else{
            l = mid +1 ;
        }

    }
    int totalPositive = n - firstPositive ;
    int totalNegative =  first_0  ;
    
    return max(totalPositive , totalNegative) ;
   

}
 
int main(){
 
    vector<int> nums = {-3,-2,-1,1,2,3} ;
    cout << binaryMaximumCount(nums) ;
    return 0;
}