#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    vector<vector<int>> compress(vector<vector<int>>&points){
        int n = points.size() ;
        sort(points.begin() , points.end()) ;
        vector<vector<int>> ans ;
        ans.push_back(points[0]);

        for(int i = 1 ; i < n ; i++){
            if(ans.back()[1] > points[i][0]){
                ans.back()[1] = max(ans.back()[1] , points[i][1]) ;
            }
            else{
                ans.push_back(points[i]) ;
            }
        }
        return ans ;     
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x_coordinates ;
        vector<vector<int>>y_coordinates ;
        for(auto &i : rectangles){
            int x1 = i[0] ;
            int y1 = i[1] ;
            int x2 = i[2] ;
            int y2 = i[3] ;
            x_coordinates.push_back({x1,x2}) ;
            y_coordinates.push_back({y1,y2}) ;
        }  
        vector<vector<int>>merged_x = compress(x_coordinates) ; 
        vector<vector<int>>merged_y = compress(y_coordinates) ; 

        return (merged_x.size() >= 3 || merged_y.size() >= 3) ;
    }
 
};
int main(){
 
    Solution sol ;
    int  n = 5 ;
    vector<vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}} ;

    cout << sol.checkValidCuts(n , rectangles) ;
    
    return 0;
}