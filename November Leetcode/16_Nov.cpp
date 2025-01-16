#include<bits/stdc++.h>
 
using namespace std ;

// Brute Froce  TC : O(n*k)
vector<int>resultArray(vector<int>&nums , int k){
    int n = nums.size();

    vector<int>ans(n-k+1 , -1) ;

    for(int i =0; i <= n-k ;i++){
        int j = i+1 ;
        
        while(j < i+k && (nums[j] > nums[j-1] && nums[j] == nums[j-1]+1)){
            j++ ;
        }
        ans[i] = (j > i+k-1) ? nums[j-1]  : -1;
        
    }
    return ans ;
}

// Sliding Window TC : O(n) 

vector<int>resultArray2(vector<int>&nums , int k){
    int n = nums.size() ;
    vector<int>ans(n-k+1 , -1) ;
    int count = 0 ;
    for(int i = 1;i<k;i++){
        if(nums[i] == nums[i-1]+1){
            count++ ;
        }
        else{
            count = 1 ;
        }
    }

    if(count >= k) ans[0] = nums[k-1] ;

    int i = 1 ;
    int j = k ;

    while(j < n ){
        if(nums[j] == nums[j-1]+1){
            count++ ;
        }
        else{
            count = 1 ;
        }

        if(count >= k) ans[i] = nums[j] ;

        i++ , j++ ;
    }

    return ans ;

}


int main(){
 
    vector<int>nums = {3,2,3,2,3,2} ;
    int k = 2 ;
    vector<int>ans = resultArray2(nums , k ) ;

    for(int &i:ans ){
        cout << i << " ";
    }
    return 0;
}
