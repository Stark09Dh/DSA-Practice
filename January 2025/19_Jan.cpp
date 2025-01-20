#include<bits/stdc++.h>
 
using namespace std ;

typedef pair<int , pair<int,int>>pp;

vector<vector<int>> direction = {{0,-1},{0,1},{1,0},{-1,0}} ; 

int trapRainWater(vector<vector<int>>& heightMap) {
    int n = heightMap.size() ;
    int m = heightMap[0].size() ;
    priority_queue<pp , vector<pp> , greater<>>boundaryCells ;

    vector<vector<bool>>visited(n, vector<bool>(m,false));

    for(int row = 0 ; row < n ; row++){
        for(int col : {0,m-1}){
            boundaryCells.push({heightMap[row][col], {row,col}}) ;
            visited[row][col] = true ;
        }
    } 

    for(int col = 0 ; col < m ; col++){
        for(int row : {0,n-1}){
            boundaryCells.push({heightMap[row][col] , {row,col}});
            visited[row][col] = true ;
        }
    }

    int water = 0 ;

    while(!boundaryCells.empty()){
        pp curr = boundaryCells.top();
        boundaryCells.pop() ;

        int height = curr.first ;
        int i = curr.second.first ;
        int j = curr.second.second ;

        for(vector<int>dir : direction){
            int i_ = i+dir[0] ;
            int j_ = j+dir[1] ;

            if(i_>=0 && j_>=0 && j_ < m && i_ < n && !visited[i_][j_]){
                water += max(height - heightMap[i_][j_] , 0) ;

                boundaryCells.push({max(height , heightMap[i_][j_]),{i_,j_}});

                visited[i_][j_] = true ;
            }
        }

    }
    return water ;

}

int main(){
 
    vector<vector<int>>heightmap =  {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}} ;
    int ans = trapRainWater(heightmap) ;
    cout << ans ;
    return 0;
}