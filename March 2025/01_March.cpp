#include<bits/stdc++.h>
 
using namespace std ;

vector<int> applyOperations(vector<int>& nums) {
    int n = nums.size() ;
    int l = -1 ;
    
    for(int i = 1 ; i < n ; i++){
        if(nums[i] == nums[i-1]){
            nums[i-1] *= 2 ;
            nums[i] = 0 ;
            if(l == -1) l = i ;
        }  
    }

    for(int i = l+1 ; i < n ;i++){
        if(nums[i] != 0){
            swap(nums[i] , nums[l]) ;
            l++;
        }
        
    }

    
    return nums ;
}
 
int main(){
    vector<int> nums = {0,1} ;
    vector<int>ans = applyOperations(nums) ;

    for(int i : ans) {
        cout << i  << " ";
    }
    
    return 0;
}