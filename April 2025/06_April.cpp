#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        sort(arr.begin(),arr.end());
        
        for(int i=0; i<=n-1; i++){
            
            hash[i] = i; // initializing with current index
            for(int prev_index = 0; prev_index <=i-1; prev_index ++){
                
                if(arr[i]%arr[prev_index]==0 && 1 + dp[prev_index] > dp[i]){
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
        }
        
        int ans = -1;
        int lastIndex =-1;
        
        for(int i=0; i<=n-1; i++){
            if(dp[i]> ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);    
        }
        
        // reverse the array 
        //reverse(temp.begin(),temp.end());
        
        return temp;
    }
 
};
int main(){
 
    Solution sol ;
    vector<int>nums = {1,2,3} ;
    vector<int>ans = sol.largestDivisibleSubset(nums) ;
    for(int &i : ans){
        cout << i << " " ;
    }
    
    return 0;
}