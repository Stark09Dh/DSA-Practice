#include<bits/stdc++.h>
 
using namespace std ;

int n , m  ;
vector<vector<int>>dir= {{0,1} , {0,-1},{1,0},{-1,0}} ;

void DFS(int i , int j ,vector<vector<int>>& grid, vector<vector<bool>>&visited,int &fish){
    visited[i][j] = true ;
    fish += grid[i][j] ;
    
    for(auto &d : dir){
        int x = i + d[0] ;
        int y = j + d[1] ;
        if(x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && grid[x][y] != 0){
            DFS(x,y,grid,visited,fish) ;
        }
    } 
}

int findMaxFish(vector<vector<int>>& grid) {
    n = grid.size() ;
    m = grid[0].size() ;
    int ans = 0 ;
    vector<vector<bool>>visited(n , vector<bool>(m,false)) ;

    for(int i = 0; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            int fish = 0 ;
            if(grid[i][j] != 0){
                DFS(i , j ,grid,visited,fish) ;
                ans = max(ans , fish) ;
            } 
        }
    }   
    return ans ;  
}
 
int main(){
 
    vector<vector<int>>grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}} ;
    int ans = findMaxFish(grid) ;
    cout << ans ;
    return 0;
}