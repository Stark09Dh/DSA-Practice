#include<bits/stdc++.h>
 
using namespace std ;
int n,m;

int solve(int i , int j ,vector<vector<int>>&grid,vector<vector<int>>&dp ){
    //base case
    if(i==n-1 && j ==m-1) return 1 ;

    if(i>=n || j >=m || grid[i][j] ==1) return 0 ;

    if(dp[i][j] != -1) return dp[i][j];
    
    int right = solve(i+1,j,grid,dp);
    int down = solve(i,j+1,grid,dp);
   
    return dp[i][j] =  right+down ;

}

int uniquePathsWithObstacles(vector<vector<int>>&grid){
    n = grid.size();
    m = grid[0].size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(0,0,grid,dp);
}

 
int main(){
 
    vector<vector<int>>arr  = {{0,0,0},{0,1,0},{0,0,0}} ;
    int ans = uniquePathsWithObstacles(arr);
    cout << ans ;
    return 0;
}