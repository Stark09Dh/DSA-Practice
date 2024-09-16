#include<bits/stdc++.h>
 
using namespace std ;


vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    vector<vector<int>>ans(m,vector<int>(n));

    if(original.size() != m*n){
        return {};
    }

    int row = 0 ;
    int col = 0 ;

    for(int i=0;i<original.size();i++){
        ans[row][col] = original[i];
        col++;
        if(col == n){
            col = 0;
            row++ ;
        }
    }
    

    return ans ;
}
 
int main(){
 
    vector<int> original = {1,2,3};
    int m = 1 ; //row
    int n = 3; // col
    vector<vector<int>>ans = construct2DArray(original,m,n);

    for(int i = 0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout << ans [i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

