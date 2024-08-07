#include<bits/stdc++.h>
 
using namespace std ;

vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    int l = 0 ;
    vector<string>res ;

    for(int r=0;r<n;r++){
        if (r == n - 1 || nums[r] + 1 != nums[r + 1]) {
            if (l == r) {
                // Single number range
                res.push_back(to_string(nums[l]));
            } else {
                // Continuous range
                res.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            }
            l = r + 1;
        }
    }
    return res ;
}
 
int main(){
 
    vector<int> nums = {0,2,3,4,6,8,9};
    vector<string>ans = summaryRanges(nums);
    for(auto &it : ans){
        cout << it << " ";
    }
    return 0;
}