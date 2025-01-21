#include<bits/stdc++.h>
 
using namespace std ;


long long gridGame(vector<vector<int>>& grid) {
    long long firstRowSum = accumulate(grid[0].begin() , grid[0].end() , 0LL) ;

    long long secondRowSum = 0 ;

    long long ans = LONG_MAX ;

    for(int i = 0 ; i < grid[0].size() ;i++){
        firstRowSum -= grid[0][i] ;

        long long temp = max(firstRowSum , secondRowSum) ;

        ans = min(ans , temp) ;

        secondRowSum += grid[1][i] ;
    }

    return ans ;
}
 
int main(){
 
    vector<vector<int>>grid = {{2,5,4},{1,5,1}};
    long long ans = gridGame(grid) ;
    cout  << ans ;
    return 0;
}