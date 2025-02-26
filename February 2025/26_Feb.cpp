#include<bits/stdc++.h>
 
using namespace std ;

int kadansAlgo(vector<int>&nums){
    int n = nums.size() ;
    int maxSum = 0 ;
    int sum = 0 ;

    for(int i = 0; i < n ; i++){
        sum += nums[i] ;

        
        if(sum < 0) sum = 0 ;
        

        maxSum = max(sum , maxSum) ;
    }

    return maxSum ;

}

int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size() ;

    int first = kadansAlgo(nums) ;

    int minSum = INT_MAX ;
    int sum = 0 ;

    for(int i = 0 ; i < n ; i++){
        sum += nums[i] ;

        if(sum > 0) sum = 0;

        minSum = min(minSum , sum ) ;
    }

    return max(first , abs(minSum)) ;

}
 
int main(){
 
    vector<int> nums = {2,-5,1,-4,3,-2} ;

    cout << maxAbsoluteSum(nums) ;

    return 0;
}