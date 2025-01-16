#include<bits/stdc++.h>
 
using namespace std ;


// Brute Force TC : O(n*m) gives TLE
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int ans = 0 ;    
    for(int i = 0; i <nums1.size() ; i++){
        for(int j= 0 ; j<nums2.size() ; j++){
            int temp = nums1[i] ^ nums2[j] ;
            ans ^= temp ;
        }
    }
    return ans ;
}

// optimized apporoach TC : O(n+m) ;

int xorAllNums2(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(); 
    int m = nums2.size() ;

    int ans = 0 ;

    if(n % 2 != 0){ // if n is odd
        for(int &i:nums2){
            ans ^= i ;
        }
    }

    if(m %2 != 0){
        for(int &i: nums1){
            ans ^= i ;
        }
    }
    return ans ;
}

 
int main(){
 
    vector<int> nums1  = {2,1,3}, nums2 = {10,2,5,0} ;
    int ans = xorAllNums2(nums1 , nums2);
    cout << ans ;
    return 0;
}