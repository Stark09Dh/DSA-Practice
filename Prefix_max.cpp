#include<bits/stdc++.h>
 
using namespace std ;
 
vector<int>prefixSum(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n) ;
    ans[0] = arr[0];
    for(int i=1;i<n;i++){
        ans[i] = max(ans[i-1],arr[i]);
    }
    return ans ;
}

vector<int>suffixMax(vector<int>&arr){
    int n = arr.size();
    vector<int>ans (n);
    ans[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i] = max(ans[i+1],arr[i]);
    }
    return ans ;
}

int main(){
 
    vector<int>arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> ans = prefixSum(arr);
    vector<int> ans2 = suffixMax(arr);
    for(int nums : ans){
        cout << nums << " ";
    }
    cout<<"\n";
    for(int nums : ans2){
        cout << nums << " ";
    }
    return 0;
}