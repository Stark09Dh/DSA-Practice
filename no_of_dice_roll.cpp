#include<bits/stdc++.h>
 
using namespace std ;

int mod = 1e9+ 7 ;

int solve(int dice, int face, int tar, vector<vector<int>>&dp){
    //base case
    if(tar < 0) return 0;
    if(dice == 0 && tar != 0 ) return 0 ;
    if(tar == 0 && dice != 0) return 0 ;
    if(dice == 0 && tar == 0) return 1 ;

    if(dp[dice][tar] != -1) return dp[dice][tar] ;

    int ans = 0 ;
    for(int i=1;i<=face ;i++){
        ans = ans + solve(dice-1,face,tar-i,dp);
    }
    return dp[dice][tar] =  ans%mod ;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    return solve(n,k,target,dp) ;
}
 
int main(){
 
    int n = 2 , k =6 , t = 7 ;
    int ans = numRollsToTarget(n,k,t);
    cout << ans ;
    return 0;
}