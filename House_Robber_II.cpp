// slight difference from house robber houses are placed in adjacently

#include<bits/stdc++.h>
 
using namespace std ;
int n ;
int sol( int i ,int end, vector<int>nums) {
    if( i > end) return 0 ;

    int take = nums[i] + sol(i+2, end , nums) ;

    int not_take = sol(i+1, end , nums) ;

    return max( take , not_take) ;
}

int rob(vector<int>& nums){
    n = nums.size() ;
    int g1 = sol(1 , n-1 , nums) ;
    int g2 = sol(0 , n-2, nums) ;

    return max(g1 , g2) ;
}
 
int main(){
 
    vector<int>nums = {1,2,3,4,5} ;
    cout << rob(nums) ;
    return 0;
}