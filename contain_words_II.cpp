#include<bits/stdc++.h>
 
using namespace std ;

bool sol(vector<int>&nums, int k){
    unordered_map<int,int>mp;
    int diff ;
    int n= nums.size();
    for(int i=0;i<n;i++){
        if(mp.find(nums[i])!=mp.end()){
            diff = mp[nums[i]] - i ;
            if(abs(diff)<=k) return true ;
        }
        
        mp[nums[i]] = i ;  
    }
    return false ;
}
 
int main(){
 
    vector<int>nums = {1,2,3,1};
    int k = 3 ;
    bool ans = sol(nums,k);
    cout << (ans) ? "True" : "False" ;
    return 0;
}