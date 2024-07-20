//Minimum Size Subarray Sum

/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&arr,int target){
    int n = arr.size();
    int sum = 0;
    int res = n+1;
    int i = 0 , j = 0 ;
    while(j<n){
        while(sum < target){
            sum += arr[j];
            j++;
        } 
        while(sum >= target){
            res = min(res,j-i);
            sum -= arr[i];
            i++;
        }
       
    }
    return res ;
}
 
int main(){
 
    vector<int>arr = {2,3,1,2,4,3};
    int target = 7 ;
    int ans = sol(arr,target);
    cout << ans ;
    return 0;
}