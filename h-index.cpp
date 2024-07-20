#include<bits/stdc++.h>
 
using namespace std ;
int sol(vector<int>&arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    for(int i =0;i<n;i++){
        if(n-i <= arr[i]) return n-i;
    }
    return 0 ;
}


int main(){

    vector<int>arr = {2,2,3,4,6};
    int ans = sol(arr);
    cout << ans << " ";
    return 0;
}