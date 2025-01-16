#include<bits/stdc++.h>
 
using namespace std ;

#define P pair<int , pair<int,int>> // {time ,{i ,j}}
vector<vector<int>>direction = {{0,1},{0,-1},{1,0},{-1,0}};
int minimumTime(vector<vector<int>>& grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;

    //base case 
    if(grid[0][1] > 1 && grid[1][0] > 1){
        return -1 ;
    }

    priority_queue<P ,vector<P> , greater<P>>pq ;
    vector<vector<int>> res (n , vector<int>(m,INT_MAX)) ;
    pq.push({0 ,{0,0}});
    res[0][0] = 0 ;
    vector<vector<int>> visited(n , vector<int>(m, false));

    while(!pq.empty()){
        int time = pq.top().first ;
        int row = pq.top().second.first ;
        int col = pq.top().second.second ;

        pq.pop();

        if(row == n-1 && col == m-1){
            return res[n-1][m-1] ;
        }
        if(visited[row][col] == true ) continue;

        visited[row][col] = true ;

        for(auto & dir : direction){
            int i = row + dir[0];
            int j = col + dir[1] ;

            if(i<0 || j<0 || i >=n || j>=m){
                continue;
            }

            if(grid[i][j] <= time+1){
                pq.push({time+1,{i,j}});
                res[i][j] = time+1 ;
            }
            else if((grid[i][j]-time)%2==0){
                pq.push({grid[i][j]+1,{i,j}});
                res[i][j] = grid[i][j] + 1 ;
            }
            else{
                pq.push({grid[i][j] , {i , j}});
                res[i][j] = grid[i][j] ;
            }

        }
    }
    return res[n-1][m-1] ;

}
 
int main(){
    
    vector<vector<int>>grid = {{0,1,3,2},{5,1,2,5},{4,3,8,6}} ;
    cout << minimumTime(grid) ; 
    
    return 0;
}