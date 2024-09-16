#include<bits/stdc++.h>
 
using namespace std ;

int dfs(vector<vector<int>>&grid,int row , int col){
    if(row<0 || col<0 || row >= grid.size() || col >= grid[0].size()|| grid[row][col]!=0){
        return 0 ;
    }
    grid[row][col] = 1 ;

    return 1+ dfs(grid,row-1,col) +dfs(grid,row+1,col) +dfs(grid,row,col-1) +dfs(grid,row,col+1) ;
}

int regionsBySlashes(vector<string>& grid) {
    int n =grid.size();
    int region = 0 ;
    vector<vector<int>>expandGrid(n*3, vector<int>(n*3,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '/'){
                expandGrid[i*3][j*3 +2] = 1 ;
                expandGrid[i*3+1][j*3+1] = 1 ;
                expandGrid[i*3+2][j*3] = 1 ;
            }
            else if(grid[i][j] == '\\'){
                expandGrid[i*3][i*3] = 1 ;
                expandGrid[i*3+ 1][i*3+1] = 1 ;
                expandGrid[i*3+2][i*3+2] = 1 ;
            }
        }
    }

    for(int i=0;i<n*3;i++){
        for(int j=0;j<n*3;j++){
            if(dfs(expandGrid,i,j)){
                region++;
            }
        }
    }
    return region ;
        
}
 
int main(){
 
    vector<string>grid = {" /"," /"};
    int regions = regionsBySlashes(grid);
    cout << regions;
    return 0;
}