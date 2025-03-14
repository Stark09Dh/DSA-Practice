#include<bits/stdc++.h>
 
using namespace std ;

#define P pair<int ,pair<int,int>>
vector<vector<int>> direction = {{0,1}, {0,-1},{1,0},{-1,0}} ;


int minimumObstacles(vector<vector<int>>& grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;

    vector<vector<int>> res (n , vector<int>(m,INT_MAX));
    res[0][0] = 0 ;
    priority_queue<P,vector<P>, greater<P>> pq ;

    pq.push({0,{0,0}}) ;

    while(!pq.empty()){
        auto curr = pq.top() ;
        pq.pop();
        int d = curr.first ;
        int i = curr.second.first ;
        int j = curr.second.second ;

        for(auto &dir : direction){
            int x = i + dir[0] ;
            int y = j + dir[1] ;

            if(x<0 || y < 0 || x >= n || y >= m){
                continue;
            }
            int wt = grid[x][y]==1? 1 : 0 ;

            if(d + wt < res[x][y]){
                res[x][y] = d + wt ;
                pq.push({d+wt , {x,y}}) ;
            }
        }
    }

    return res[n-1][m-1] ;

}
 
int main(){
 
    vector<vector<int>> grid = {{0,1,1},{1,1,0},{1,1,0}} ;
    cout << minimumObstacles(grid) ;
    return 0;
}

