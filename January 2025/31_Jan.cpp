#include<bits/stdc++.h>
 
using namespace std ;
int n ;
vector<vector<int>>direction = {{-1,0} , {1,0}, {0,-1} ,{0,1}} ; 

int dfs(vector<vector<int>>& grid , int i , int j ,int id){
    if(i<0 || i >= n || j < 0  || j>=n || grid[i][j] != 1 ){
        return 0 ;
    }
    grid[i][j] = id ;
    int size = 1 ;

    for(vector<int> dir : direction){
        int x = i + dir[0] ;
        int y = j + dir[1] ;
        size += dfs(grid,x,y,id) ;
    }
    return size ;
}

int largestIsland(vector<vector<int>>& grid) {
    n = grid.size() ;

    int maxArea = 0 ;

    int id = 2 ;
    unordered_map<int,int>mp ;
    for(int i = 0 ; i < n ; i++){
        for(int j=  0 ;j < n ; j++){
            if(grid[i][j] == 1){
                int size = dfs(grid,i,j,id) ;
                maxArea = max(maxArea , size) ;
                mp[id] = size ;
                id++ ;

            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j=  0 ;j < n ; j++){
            if(grid[i][j] == 0 ){
                unordered_set<int>uniqueID ;
                for(auto &dir : direction){
                    int x = i + dir[0] ;
                    int y = j + dir[1] ;
                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0){
                        uniqueID.insert(grid[x][y]) ;
                    }
                }
                int overAllsize = 1 ;
                for(auto &it : uniqueID){
                    overAllsize += mp[it] ;
                }

                maxArea = max(maxArea , overAllsize) ;
            }
        }
    }

    return maxArea ;
    
}
 
int main(){
 
    vector<vector<int>> grid = {{1,0},{0,1}} ;
    int ans = largestIsland(grid) ;
    cout << ans ;
    return 0;
}