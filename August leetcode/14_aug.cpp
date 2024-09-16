#include<bits/stdc++.h>
 
using namespace std ;

int n;

int countPairs(vector<int>nums,int mid){
    int count = 0  ;
    int left = 0 ;

    for(int i =0 ;i<n ;i++){

        while(nums[i]- nums[left] > mid){
            left++;
        }
        count += i - left ;
    }
    return count ;
}
int smallestDistancePair(vector<int>& nums, int k) {
    n = nums.size();
    sort(nums.begin(),nums.end());
    int low = 0 , high = nums[n-1] - nums[0] ;
    while(low < high){

        int mid = (low+high)/2 ;

        int count = countPairs(nums,mid);

        if(count < k){
            low = mid+1 ;
        }
        else{
            high = mid ;

        }
    }
    return low ;
}
 
int main(){
 
    vector<int>nums = {1,2,4,5} ;
    int k = 3 ;
    int ans = smallestDistancePair(nums , k);
    cout << ans ;
    return 0;
}