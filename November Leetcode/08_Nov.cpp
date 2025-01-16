#include<bits/stdc++.h>
 
using namespace std ;


// Gives TLE as TC : O(n* 2^maxBit-1)

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n= nums.size() ;
    int limit = 1 << maximumBit ;
    vector<int>ans(n,0) ;
    vector<int>prefix(n) ;
    prefix[0] = nums[0] ;

    for(int i =1 ; i<n ; i++){
        prefix[i] = prefix[i-1] ^ nums[i] ;
    }

    for(int i= 0;i < n ; i++){
        int val = 0 ;
        int idx = -1 ;
        for(int j=0;j<limit ; j++){
            if(val < (prefix[n-i-1] ^ j)){
                val = prefix[n-i-1] ^ j ;
                idx = j ;
            }
        }
        ans[i] = idx ;
    }

    return ans ;

}

vector<int>getMaximumXor2(vector<int>nums, int maximumBit){
    int n= nums.size() ;
    int limit = (1 << maximumBit) -1 ;
    vector<int>ans(n) ;
    int prefix = 0 ;
    for(int i=0;i<n;i++){
        prefix ^= nums[i] ;
        ans[n-i-1] = limit ^ prefix ;
    }

    return ans ;
}

 
int main(){
 
    vector<int>nums = {0,1,1,3} ;
    int maximumBit =  2 ;
    vector<int>ans = getMaximumXor2(nums , maximumBit) ;
    for(int &i : ans ){
        cout << i << " " ;
    }

    
    return 0;
}