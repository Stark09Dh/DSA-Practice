#include<bits/stdc++.h>
 
using namespace std ;

long long maximumSubarraySum(vector<int>& nums, int k) {
    int n = nums.size() ;
    long long ans = 0; 
    long long sum = 0 ;
    unordered_set<int>st ;

    int i = 0 , j =  0 ;

    while(j< n){

        while(st.count(nums[j])){
            sum -= nums[i];
            st.erase(nums[i]) ;
            i++ ;
        }

        sum += nums[j] ;

        st.insert(nums[j]) ;

        if(j-i+1 == k){
            ans = max(ans , sum ) ;
            sum -= nums[i] ;
            st.erase(nums[i]) ;
            i++;
        }
        j++ ;
    }
    return ans ;  
}
 
int main(){
 
    vector<int>nums = {1,5,4,2,9,9,9,} ;
    int k = 3  ;
    cout << maximumSubarraySum(nums , k) ;
    return 0;
}