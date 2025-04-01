#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:

    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<int> vec ;
        for(int i= 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                vec.push_back(grid[i][j]) ;
            }
        }
        int size = vec.size() ;

        sort(vec.begin() , vec.end()) ;
        int target = vec[size/2] ;
        int ans = 0 ;

        for(int &num : vec) {
            if(num % x != 0) return -1 ;

            ans += abs(target - num) / x ;

        }
        return ans ;
    }
 
};
int main(){
 
    Solution sol ;
    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2 ;
    cout << sol.minOperations(grid , x );
    
    return 0;
}