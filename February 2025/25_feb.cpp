#include<bits/stdc++.h>
 
using namespace std ;
const int mod = 1e9 + 7 ;

// Brute Force
int numOfSubarrays(vector<int>&arr){
    int n = arr.size() ;
    int ans = 0 ;
    vector<int>Sum ;

    for(int l = 0 ; l < n ; l++){
        int r = l ;
        int sum = 0 ; 
        while(r < n){
            sum += arr[r] % mod ;
            r++; 
            Sum.push_back(sum%mod) ;
        }
        
    }
    for(int &i : Sum){
        if(i & 1) ans++;
    }
    return ans ;
}

// Optimised
int numOfSubarrays_2(vector<int>&arr){
    int n = arr.size() ;
    int ans = 0 ;
    int even_count = 1 , odd_count = 0 , running_sum = 0;

    for(int i = 0 ;  i < n ; i++){
        running_sum = ( running_sum + arr[i] ) % mod ;
        
        if(running_sum % 2 == 0){
            ans += odd_count ;
            even_count++ ;
        }
        else if(running_sum % 2 != 0){
            ans += even_count ;
            odd_count++ ;
        }

        ans %= mod ;
    }
    
    return ans ;
}

 
int main(){
 
    vector<int>nums = {1,3,5} ;
    cout << numOfSubarrays_2(nums) ;
    return 0;
}