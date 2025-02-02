#include<bits/stdc++.h>
 
using namespace std ;


long long determinant(vector<vector<long long>>&m) {
    int n = m.size() ;
    if(n == 1 ) return m[0][0] ;
    if(n == 2) return m[0][0]*m[1][1] - m[0][1]*m[1][0] ;

    long long det = 0 ;
    

    for(int col = 0 ; col < n ; col++){
        vector<vector<long long>>minors(n-1,vector<long long>(n-1)) ;
        for(int i = 1 ; i <n ; i++){
            int subj = 0;
            for(int j = 0 ; j < n ; j++){
                if(col == j) continue ;
                minors[i-1][subj] = m[i][j] ;
                subj++ ;
            }
        }
        det += (col % 2 == 0 ? 1 : -1) * m[0][col] * determinant(minors);
    }
    return det;
}
 
int main(){
 
    vector<vector<long long>>matrix = {{2,5,3},{1,-2,-1},{1,3,4}} ;
    long long ans = determinant(matrix) ;
    cout << ans; 
    
    return 0;
}