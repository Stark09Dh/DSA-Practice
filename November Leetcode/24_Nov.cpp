#include<bits/stdc++.h>
 
using namespace std ;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size() ;
    int m = matrix[0].size() ;
    int number_of_neg = 0 ;
    int min_element = INT_MAX ;
    long long sum = 0;

    for(int i = 0 ; i<n ; i++){
        for(int j= 0;j<m;j++){
            if(matrix[i][j]  < 0){
                number_of_neg++ ;
            }
            min_element = min(min_element , abs(matrix[i][j])) ;

            sum += abs(matrix[i][j]) ;
        }
    }
    
    return (number_of_neg % 2 == 0) ? sum : sum-(2*min_element) ;
}
 
int main(){
 
    vector<vector<int>>matrix = {{1,2,3},{-1,-2,-3},{1,2,3}} ;

    cout << maxMatrixSum(matrix) ;

    return 0;
}