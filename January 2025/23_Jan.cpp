#include<bits/stdc++.h>
 
using namespace std ;

int countServers(vector<vector<int>>& grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<int>row(n,0) , col(m,0) ;
    int totalServer = 0 ;
    

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1){
                row[i]++ , col[j]++ ;
                totalServer++ ;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If there's a server at (i, j) and it's in a row or column with more than 1 server
            if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                result++;
            }
        }
    }
    
    return result;
}
 
int main(){
 
    vector<vector<int>> grid = {{1,0} , {0,1}} ;
    int ans = countServers(grid);
    cout << ans ;
    return 0;
}