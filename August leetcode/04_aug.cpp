#include<bits/stdc++.h>
 
using namespace std ;

int rangeSum(vector<int>& nums, int n, int left, int right) {
        
    vector<int>subSum ;

    for(int i=0;i<n;i++){
        vector<int>subArray ;
        for(int j=i;j<n;j++){
            subArray.push_back(nums[j]);
            int sum = accumulate(subArray.begin(),subArray.end(),0);
            subSum.push_back(sum);
        }
    }
    sort(subSum.begin(),subSum.end());
    int ans = 0;
    for(int i = left-1 ; i<right;i++){
        ans+= subSum[i];
    }
    return ans;
}

//1, 3, 6, 10, 2, 5, 9, 3, 7, 4
 
int main(){
 
    vector<int> nums = {1,2,3,4};
    int n = 4 , left = 1 , right =  10 ;
    int ans = rangeSum(nums,n,left,right);
    cout <<ans ;

    // vector<int>ans = rangeSum(nums,n,left,right);
    // for(int &i:ans){
    //     cout << i << " ";
    // }
    return 0;
}