#include<bits/stdc++.h>
 
using namespace std ;

vector<vector<int>>sol(vector<int>&nums){
    vector<vector<int>>res ;
    sort(nums.begin(),nums.end());
    int n= nums.size();
    for(int i=0;i<n;i++){
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i+1;
        int k = n-1;
        while(j< k){
            int temp = nums[i] + nums[j] + nums[k];
            if(temp > 0){
                k--;
            }
            else if(temp < 0){
                j++;
            }
            else{
                res.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return res ;
}
 
int main(){
 
    vector<int>nums = {-1,0,1,2,-1,-4};
    vector<vector<int>>ans = sol(nums);
    return 0;
}