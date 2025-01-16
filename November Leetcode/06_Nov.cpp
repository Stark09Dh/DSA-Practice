#include<bits/stdc++.h>
 
using namespace std ;

bool canSortArray(vector<int>& nums) {
    int n = nums.size();
    bool swaps =  true ;
    for(int i=0;i<n;i++){
        swaps=false ;
        for(int j=0; j < n-i-1 ; j++){
            if(nums[j] <= nums[j+1]){
                continue;
            }
            else{
                if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){
                    swap(nums[j],nums[j+1]) ;
                    swaps = true ;
                }
                else{
                    return false ;
                }
            }
        }
        if(!swaps) break ;
    }
    return true ;
}
 
int main(){
 
    vector<int>nums = {8,4,2,30,15} ; //{1,1,1,,4,4}
    cout << canSortArray(nums);
    return 0;
}

// {1,2,3,4,5} --> set bits = {1,1,2,1,2}