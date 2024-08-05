#include<bits/stdc++.h>
 
using namespace std ;

int n , m ;

int solve(int i, int j,vector<vector<int>>&arr,vector<vector<int>>&dp){
    //base case 
    if(i>=n || j >= m) return INT_MAX;

    if (i == n - 1 && j == m - 1) return arr[i][j];
    
    if(dp[i][j] != -1) return dp[i][j] ;

    int right =  solve(i,j+1,arr,dp);  
    
    int down =   solve(i+1,j,arr,dp);
    
    return dp[i][j] =  arr[i][j] + min(right,down) ;

}

int minPathSum(vector<vector<int>>&arr){
    n = arr.size();
    m = arr[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(0,0,arr,dp);
}
 
int main(){
 
    vector<vector<int>>arr = {{1,3,1},{1,5,1},{4,2,1}};
    int ans = minPathSum(arr);
    cout << ans ;
    return 0;
}