#include<bits/stdc++.h>
 
using namespace std ;

int n ,m ;

int sol(int i, int j , vector<vector<int>>& grid , vector<vector<int>>&dp ){
    if( i >= n || j >= m || i<0 ) {
        return  0 ;

    }
    if(dp[i][j] != -1) return dp[i][j] ;

    int right =0 , updaig=0  , lowdaig =0 ;

    if(j+1 < m && i < n && grid[i][j] < grid[i][j+1]){
        right = 1 + sol(i,j+1,grid,dp) ;
    }
    if(i+1<n && j+1 < m && grid[i][j] < grid[i+1][j+1]){
        lowdaig = 1+ sol(i+1,j+1,grid,dp);
    }

    if(i-1>=0 && j+1 < m && grid[i][j] < grid[i-1][j+1]){
        updaig = 1 + sol(i-1,j+1,grid,dp) ;
    }

    return dp[i][j] =  max({right , updaig , lowdaig}) ;
}

int maxMoves(vector<vector<int>>& grid) {
    int res = 0 ;
    n = grid.size() ;
    m = grid[0].size() ;

    vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1)) ;

    for(int i = 0; i < n ; i++) {
        res = max(res , sol(i,0,grid,dp));
    }    

    return res ;
}
 
int main(){
 
    vector<vector<int>> grid = {{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}} ;

    cout << maxMoves(grid) ;

    return 0;
}