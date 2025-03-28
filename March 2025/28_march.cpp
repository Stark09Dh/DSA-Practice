#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution {
public:
    vector<vector<int>> dirn = {{0,1},{1,0},{-1,0},{0,-1}} ;
    
    typedef pair<int ,pair<int,int>> P ;

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int k = queries.size() ;
        int count = 0 ;
        vector<int>ans(k,0) ;
        vector<vector<bool>>vis(n,vector<bool>(m , false)) ;
        vector<pair<int,int>>valtoidx;
        for(int i =0 ; i < k ; i++){
            valtoidx.push_back({queries[i],i}) ;
        }
        sort(valtoidx.begin() , valtoidx.end()) ;

        priority_queue<P , vector<P>, greater<>> pq;

        pq.push({grid[0][0], {0,0}}) ;
        vis[0][0] = true ;

        for(auto &[q, idx] : valtoidx){
            while(!pq.empty() && pq.top().first < q){
                auto [val ,pos] = pq.top() ; pq.pop() ;
                count++ ;
                int r = pos.first , c = pos.second ;

                for(auto &dir : dirn){
                    int x = r + dir[0] ;
                    int y = c + dir[1] ;
                    if(x >= 0 && y >= 0 && x < n  && y < m && !vis[x][y]){
                        pq.push({grid[x][y] , {x,y}}) ;
                        vis[x][y] = true ;
                    }
                }
            }
            ans[idx] = count ;
        }
        return ans ;


        
        return ans ;
    }
};

int main(){
    vector<vector<int>>grid  = {{1,2,3},{2,5,7},{3,5,1}};
    vector<int> queries = {5,6,2} ;
    Solution sol ;
    vector<int>res = sol.maxPoints(grid , queries) ;
    for(auto &i : res){
        cout << i << " " ;
    }
    return 0;
}