#include<bits/stdc++.h>
 
using namespace std ;
vector<int>sol(vector<int>&arr, int tar){
    unordered_map<int ,int>mp;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        int diff = tar - arr[i];
        if(mp.find(diff) != mp.end()){
            ans.push_back(i);
            ans.push_back(mp[diff]);
        }
        else{
            mp[arr[i]] = i;
        }
    }
    return ans ;
}
 
int main(){
 
    vector<int> arr = {2,6,5,8,11};
    int target = 14;
    vector<int>ans = sol(arr,target);
    for(int i : ans){
        cout << i <<" ";
    }
    return 0;
}