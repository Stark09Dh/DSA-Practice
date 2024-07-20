#include<bits/stdc++.h>
 
using namespace std ;

vector<int>sol(vector<int>&arr,int target){
    int n = arr.size();
    int l=0,r=n-1;
    vector<int>ans;
    while(l<=r){
        int temp = arr[l] + arr[r];
        if(temp > target){
            r--;
        }
        else if(temp < target){
            l++;
        }
        else{
            ans.push_back(l+1);
            ans.push_back(r+1);
            break;
        }
    }
    return ans ;
}
 
int main(){
 
    vector<int>arr = {2,3,4};
    int target = 6;
    vector<int>ans = sol(arr,target);
    for(int nums : ans){
        cout << nums << " ";
    }
    return 0;
}