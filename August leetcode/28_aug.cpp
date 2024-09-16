#include<bits/stdc++.h>
 
using namespace std ;

bool checkSubIsland(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i, int j){
    if(i<0 || j < 0 || i >=grid2.size() || j >=grid2[0].size()) return true;

    if(grid2[i][j] != 1) return true ;

    grid2[i][j] = -1 ; // visited

    bool result = (grid1[i][j] == 1);

    result = result & checkSubIsland(grid1,grid2,i+1,j);
    result = result & checkSubIsland(grid1,grid2,i-1,j);
    result = result & checkSubIsland(grid1,grid2,i,j+1);
    result = result & checkSubIsland(grid1,grid2,i,j-1);

    return result ;
} 

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int subIslands = 0 ;
    int n = grid2.size();
    int m = grid2[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid2[i][j] == 1 && checkSubIsland(grid1,grid2,i,j)){
                subIslands++ ;
            }
        }
    }

    return subIslands ;

}
 
int main(){

    vector<vector<int>>grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>>grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};

    int ans = countSubIslands(grid1,grid2);

    cout << ans ;
    
    return 0;
}