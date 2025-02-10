#include<bits/stdc++.h>
 
using namespace std ;

//  i < j and j - i != nums[j] - nums[i].

// simple brute Force
long long countBadPairs(vector<int>& nums) {
    int count = 0 ;
    int n = nums.size() ;
    unordered_map<int,int> mp ;
    for(int i =0 ; i < n ; i++){
        int diff = nums[i] - i ;
        count += mp[diff] ;
        mp[diff]++;
    }
    int total = (n*(n-1))/2 ;

    return total - count ;

}
 
int main(){
 
    vector<int> nums = {1,2,3,4,5} ;
    cout << countBadPairs(nums) ;
    return 0;
}