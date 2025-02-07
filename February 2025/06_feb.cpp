#include<bits/stdc++.h>
 
using namespace std ;

int nC2(int &n){
    return (n*(n-1)) / 2 ;
}

int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int ,int> mp ;
    for(int i= 0 ; i <  n; i++){
        for(int j = i+1; j<n ; j++){
            mp[nums[i]*nums[j]]++;

        }
    }
    int count = 0 ;
    for(auto &i: mp){
        count += 8 * nC2(i.second) ;
    }
    return count ;
}
 
int main(){
 
    vector<int>nums = {2,4,3,6} ;
    int ans = tupleSameProduct(nums) ;
    cout << ans ;
    return 0;
}