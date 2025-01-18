#include<bits/stdc++.h>
 
using namespace std ;
vector<vector<int>> dir = {{0, 1} , {0,-1},{1,0},{-1,0}} ;

int minCost(vector<vector<int>>& grid) {
   
    int n = grid.size() ; 
    int m = grid[0].size() ;
    vector<vector<int>>ans(n , vector<int>(m,INT_MAX)) ;
    priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>>pq;
    pq.push({0,0,0}) ;

    ans[0][0] = 0 ;

    while(!pq.empty()){
        auto curr = pq.top() ;
        pq.pop() ;

        int currCost = curr[0] ;
        int i = curr[1] ;
        int j = curr[2] ;

        for(int  dir_i = 0 ; dir_i <= 3 ; dir_i++){
            int i_ = i + dir[dir_i][0] ;
            int j_ = j + dir[dir_i][1] ;

            if( i_ >= 0 && j_ >= 0 && i_ < n && j_ < m){
                int gridDir = grid[i][j] ;
                int dirCost =  ((gridDir-1 != dir_i) ? 1 : 0) ;

                int newCost = currCost + dirCost ;

                if(newCost < ans[i_][j_]){
                    ans[i_][j_] = newCost ;
                    pq.push({newCost ,i_ , j_}) ;
                }

            }
        }
        
    }
    return ans[n-1][m-1] ;
    
}
 
int main(){
 
    vector<vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}} ;
    int ans = minCost(grid);
    cout << ans ;
    return 0;
}