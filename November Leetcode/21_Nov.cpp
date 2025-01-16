#include<bits/stdc++.h>
 
using namespace std ;

void markGuarded(int row , int col , vector<vector<char>>&fort){
    // UP
    for(int i = row - 1 ; i >= 0 ; i--){
        if(fort[i][col] == 'G' || fort[i][col]=='W'){
            break ;
        }
        fort[i][col] = 'O' ;
    }
    // Down
    
    for(int i = row + 1 ; i < fort.size() ; i++){
        if(fort[i][col] == 'G' || fort[i][col]=='W'){
            break ;
        }
        fort[i][col] = 'O' ;
    }
    //left
    for(int j = col - 1 ; j>=0 ; j--){
        if(fort[row][j] == 'G' || fort[row][j]=='W'){
            break ;
        }
        fort[row][j] = 'O' ;
    }
    // Right
    for(int j = col + 1 ; j < fort[0].size() ; j++){
        if(fort[row][j] == 'G' || fort[row][j]=='W'){
            break ;
        }
        fort[row][j] = 'O' ;
    }

}

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<char>>fort (m , vector<char>(n,'U')) ;

    for(auto &i : guards){
        int r = i[0] ;
        int c = i[1] ;
        fort[r][c] = 'G' ;
    }
    for(auto &i : walls){
        int r = i[0] ;
        int c = i[1] ;
        fort[r][c] = 'W' ;
    }

    for(auto &i : guards){
        int r = i[0];
        int c = i[1] ;
        markGuarded(r , c , fort) ;
        
    }
    int ans = 0 ;

    for(int i=0;i<m;i++){
        for(int j = 0 ;j<n;j++){
            if(fort[i][j] == 'U'){
                ans++ ;
            }
        }
        
    }

    return ans ;

}
 
int main(){
 
    int row = 4, col = 6 ; 
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}}, walls = {{0,1},{2,2},{1,4}} ;

    cout << countUnguarded(row , col , guards , walls) ;


    return 0;
}