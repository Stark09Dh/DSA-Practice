#include<bits/stdc++.h>
 
using namespace std ;
// Brute Force TC : O(n*m) 
bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
    for(int i=0;i<matrix.size() ; i++){
        for(int j= 0  ;j<matrix[0].size() ; j++){
            if(matrix[i][j] = target){
                return true ;
            }
        }
    }  
    return false ;
}

// Better Solution TC : O(n* log(m)) ;
int binary_Search(vector<int> nums , int target) {
    int l= 0  , r = nums.size() - 1 ;

    while(l <= r){
        int mid = ( l + r ) / 2 ;

        if( nums[mid] == target) {
            return true ;
        }
        else if(nums[mid] >target){
            r = mid - 1 ;
        }
        else{
            l = mid+ 1 ;
        }
    }
    return false ;

}

bool searchMatrix_2(vector<vector<int>>& matrix, int target) {
    for(int i= 0 ; i< matrix.size() ; i++){
        int ind = binary_Search(matrix[i] , target) ;
        if(ind) return true ;
    }
    return false ;
}

// Optimat Approach TC : O( n + m) 
bool searchMatrix_3(vector<vector<int>>& matrix, int target) {
    int row = 0 , col = matrix[0].size() -1 ;
    while( row < matrix.size() && col>=0){
        if(matrix[row][col] == target){
            return true ;
        }
        else if(matrix[row][col] > target){
            col-- ;
        }
        else{
            row++ ;
        }
    }
    return false ;
}


 
int main(){
    vector<vector<int>> matrix={{1,4,7,11,15},
                                {2,5,8,12,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}
                                } ;
    int target = 5 ;

    cout << searchMatrix_3(matrix , target );
    return 0;
}