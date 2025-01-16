#include<bits/stdc++.h>
 
using namespace std ;

int findChampion(int n, vector<vector<int>>& edges) {

    vector<int>parent(n , -1) ;

    for(auto i : edges){
        parent[i[1]] = i[0] ;
    }

    int ans = -1 ;
    int count = 0 ;

    for(int i= 0 ; i<n;i++){
        if(parent[i] == -1){
            count++ ;
            ans = i ;
        }
        if(count >1){
            return -1 ;
        }
    }

    return ans ;
        
}
 
int main(){
    int n = 3 ;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}} ;
    cout << findChampion(n , edges) ;
    return 0;
}