#include<bits/stdc++.h>
 
using namespace std ;

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map< string , int > mp ;

    
    for(int i = 0 ; i < matrix.size() ; i++){
        string s = "" ;
        if(matrix[i][0] == 1){
            for(int j = 0 ; j<matrix[0].size() ; j++){
                s += to_string(!matrix[i][j]) ;
            }
        }
        else{
            for(int j = 0 ; j<matrix[0].size() ; j++){
                s += to_string(matrix[i][j]) ;
            }
        }
        mp[s] += 1 ;
    }

    int ans  = 0 ; 
    for(auto it : mp){
        ans = max(ans , it.second) ;
    }

    return ans ;

    
}
 
int main(){
 
    vector<vector<int>>matrix = {{0,0,0},{0,0,1},{1,1,0}} ;

    cout << maxEqualRowsAfterFlips(matrix) ;
    return 0;
}