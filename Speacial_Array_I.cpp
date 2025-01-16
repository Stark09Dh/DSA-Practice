#include<bits/stdc++.h>
 
using namespace std ;

bool isArraySpecial(vector<int>& nums) {
    int n = nums.size() ;
    if(n <= 1 ) return true ;
    for(int i=1;i<n;i++){
        if(nums[i]%2 == nums[i-1]%2){
            return false ;
        }
    }

    return true ;
}
 
int main(){
 
    vector<int>nums = {4,3,1,6} ;

    cout << isArraySpecial(nums) ;

    return 0;
}