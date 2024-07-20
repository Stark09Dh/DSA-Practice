// Find the maximum sum of a subarray from a given array 

#include<bits/stdc++.h>
 
using namespace std ;

int soll(vector<int>&arr){
    int n = arr.size();
    int sum1 = arr[0] + arr[1] + arr[2] ;
    int i = 1 , j = i+2 ;
    int ans = sum1 ;
    while(j < n){
        int temp = sum1 + arr[j] - arr[i];
        sum1 = temp ;
        ans = max(ans , sum1);
        i++,j++;
    }
    return ans ;
}
 
int main(){
 
    vector<int>arr = {2,3,5,2,9,7};
    int res = soll(arr);
    cout << res ;
    return 0;
}