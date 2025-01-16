#include<bits/stdc++.h>
 
using namespace std ;

int n ,m;

int sol(int i , int j ,vector<vector<int>>& dungeon ,vector<vector<int>>&dp){
    if( i >= n || j >= m) return INT_MAX ;

    if(dp[i][j] != -1) return dp[i][j] ;

    int health = min(sol(i+1,j , dungeon,dp) , sol(i,j+1,dungeon,dp)) ;

    if(health == INT_MAX){
        health = 1  ;
    }

    int res = 0 ;

    if(health - dungeon[i][j] > 0){
        res = health - dungeon[i][j] ;
    } 
    else{
        res = 1 ;
    }

    return dp[i][j] =  res ;
}

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    n = dungeon.size();
    m = dungeon[0].size();
    if(n == 0 || m == 0) return 0 ;
    vector<vector<int>>dp(n+1,vector<int>(m+1 , -1));
    return sol(0 ,0,dungeon,dp) ;
  
}
 
int main(){
 
    vector<vector<int>>dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}} ; 

    cout << calculateMinimumHP(dungeon) ;
    return 0;
}