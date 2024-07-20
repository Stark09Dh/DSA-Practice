#include<bits/stdc++.h>
 

using namespace std ;

// minimum in row
// maximum in col

vector<int> luckyNumbers (vector<vector<int>>& matrix){
    int n = matrix.size();
    int m=  matrix[0].size();

    int minr = INT_MIN ;
    for(int i=0;i<n;i++){
        int tempmin = matrix[i][0];
        for(int j=0;j<m;j++){
            if(matrix[i][j] < tempmin){
                tempmin = matrix[i][j];
            }
        }
        minr = max(minr, tempmin);
    }
    int maxc = INT_MAX ;
    for(int i=0;i<m;i++){
        int tempmax = INT_MIN ;
        for(int j=0;j<n;j++){
            tempmax = max(tempmax,matrix[j][i]);
        } 
        maxc = min(tempmax,maxc);
    }
    return {maxc};
}
 
int main(){
 
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};

    vector<int>ans = luckyNumbers(matrix);

    for( int i : ans){
        cout << i ;
    } 
    return 0;
}