#include<bits/stdc++.h>
 
using namespace std ;

int binary_search(vector<vector<int>> &arr,int l , int r,int element){
    int n = arr.size();
    int m = arr[0].size();
    while(l < r) {
        int middle = l+(r-l)/2 ;
        int row = middle/ m ;
        int col = middle % m ;

        if(arr[row][col] == element) return true ;
        else if(element < arr[row][col]) l= middle-1 ;
        else r = middle+1 ;
    }
    return false ;
}

 
int main(){
 
    vector<vector<int>>arr = {{1,3,5,7},{10,11,16,20},{23,30,34,60}} ;
    int target = 3 ;
    int n = arr.size();
    int m = arr[0].size();
    int high = n*m - 1 ;
    bool present = binary_search(arr,0,high,target);

    cout<< present;
    return 0;
}