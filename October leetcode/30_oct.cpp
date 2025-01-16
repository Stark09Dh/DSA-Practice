#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>nums){
    int n = nums.size() ;
    vector<int>LIS(n,1);
    vector<int>LDS(n,1);
 
    // LIS
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    // LDS 
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[i] > nums[j]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    int mountain= 0 ;

    for(int i=1;i<n-1;i++){
        if (LIS[i] > 1 && LDS[i] > 1) {
            mountain = max(mountain, LIS[i] + LDS[i] - 1);
        }
    }

    return n - mountain ; 

}
 
int main(){
 
    vector<int> nums = {100,92,85,74,64,66,64} ;
    cout << sol(nums) ;

    return 0;
}