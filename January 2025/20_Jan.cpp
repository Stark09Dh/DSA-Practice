#include<bits/stdc++.h>
 
using namespace std ;

//brute Force Approach TLE : O(k*n*m) , k = arr.size() , n = mat.size() , m = mat[0].size()
int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int n = mat.size() ;
    int m = mat[0].size();
    vector<int>row(n,0) , col(m,0) ;

    

    for(int i = 0 ; i < arr.size() ; i++){
        int num = arr[i] ;
        for(int j = 0 ;j<n;j++){
            for(int k = 0;k<m;k++){
                if(mat[j][k] == num){
                    row[j]++ ;
                    col[k]++;
                    if(row[j] == m || col[k] == n){
                        return i ;
                    }
                }
            }
        }
    }
    return -1 ;
}

// Better Approach TLE : O(n*m + k) , k = arr.size() , n = mat.size() , m = mat[0].size()
int firstCompleteIndex2(vector<int>& arr, vector<vector<int>>& mat) {
    int n = mat.size() ;
    int m = mat[0].size();
    vector<int>row(n,0) , col(m,0) ;

    unordered_map<int,pair<int,int>>mp ;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            mp[mat[i][j]] = {i,j} ;
        }
    }

    for(int i = 0 ; i < arr.size() ; i++){
        int num = arr[i] ;
        int x = mp[num].first ;
        int y = mp[num].second ;

        row[x]++ ;
        col[y]++ ;

        if(row[x] == m || col[y] == n){
            return i ;
        }
    }
    return -1 ;
}
 
int main(){
 
    vector<int>arr = {2,8,7,4,1,3,5,6,9};
    
    vector<vector<int>> mat = {{3,2,5},{1,4,6},{8,7,9}} ;

    int ans = firstCompleteIndex2(arr,mat) ;

    cout << ans ;
    return 0;
}