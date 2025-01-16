#include<bits/stdc++.h>
 
using namespace std ;

void updateWindow(int num , vector<int>&vec , int val){
    for(int i=0;i<32;i++){
        if((num >> i) & 1){
            vec[i] += val ;
        }
    }
}

int getDecimalNumber(vector<int>&vec){
    int num = 0 ;
    for(int i=0;i<32;i++){
        if(vec[i] > 0){
            num |= (1 << i) ;
        }
    }

    return num ;
}


int minimumSubarrayLength(vector<int>& nums, int k) {
    int n = nums.size() ;

    int res = INT_MAX ;

    int i= 0 , j = 0 ;

    vector<int>vec(32,0) ;

    while(j<n){
        updateWindow(nums[j] , vec, 1); 

        while( i <= j && getDecimalNumber(vec) >= k){
            res = min(res , j-i+1);
            updateWindow(nums[i] , vec,-1) ;
            i++;

        }
        j++ ;
    }
    return res == INT_MAX ? -1 : res  ;
}
 
int main(){
 
    vector<int>nums= {2,1,8};
    int k = 10 ;
    cout << minimumSubarrayLength(nums,k);
    return 0;
}