#include<bits/stdc++.h>
 
using namespace std ;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    unordered_map<int , int> mp ;
    for(vector<int> vec : grid){
        for(int i : vec) {
            mp[i]++;
        }
    }
    int limit = n*n ;
    vector<int>ans(2) ;
    for(int i = 1 ; i<= limit ; i++){
        if(mp.find(i) == mp.end()){
            ans[1] = i ;
        }
        else if(mp[i] > 1){
            ans[0] = i ;
        }
    }
    return ans ;
    

}
 
int main(){
    vector<vector<int>>grid = {{9,1,7},{8,9,2},{3,4,6}} ;

    vector<int> ans = findMissingAndRepeatedValues(grid) ;

    cout <<"[ " ;
    for(int i : ans){
        cout << i << " " ;
    }
    cout << ']' ;
    
    return 0;
}