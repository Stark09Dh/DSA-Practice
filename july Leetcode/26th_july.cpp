// 1334. Find the City With the Smallest Number of Neighbors at a Threshold matrixance

#include<bits/stdc++.h>
#define INF 99999999
using namespace std ;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    
    vector<vector<int>>matrix(n,vector<int>(n,INF));
    for(auto &it : edges){
        matrix[it[0]][it[1]] = it[2];
        matrix[it[1]][it[0]] = it[2];
    }
    for(int i=0;i<n;i++) matrix[i][i] = 0 ;

    int i, j, k;
    for (k = 0; k < n; k++) {
        
        for (i = 0; i < n; i++) {
            
            for (j = 0; j < n; j++) {
                
                if (matrix[i][j] > (matrix[i][k] + matrix[k][j])
                    && (matrix[k][j] != INF
                        && matrix[i][k] != INF))
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    int cntCity = n ;
    int city = -1 ;
    for(int i = 0 ; i<n;i++){
        int cnt = 0 ;
        for(int j=0;j<n;j++){
            if(matrix[i][j] <= distanceThreshold){
                cnt++;
            }
        }
        if(cnt <= cntCity){
            cntCity = cnt ;
            city = i ;
        }
    }
    return city ;

}
 
int main(){
 
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int matrixanceThreshold = 4 ;
    int n = edges.size();

    int ans = findTheCity(n,edges,matrixanceThreshold);
    cout << ans ;
    return 0;
}