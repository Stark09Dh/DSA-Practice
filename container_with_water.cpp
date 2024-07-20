// leetcode : 11 Container with most Water 

#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&arr){
    int n = arr.size();
    int i = 0 ;
    int j = n-1 ;
    int ans = 0;
    while(i < j ){
        int storage = min(arr[i],arr[j]) * (j-i);
        if(arr[i] < arr[j]){
            i++;
        }
        else{
            j--;
        }
        ans = max(ans,storage);
    }
    return ans ;
}
 
int main(){
 
    vector<int>arr = {1,1};
    int ans = sol(arr);
    cout << ans << " ";
    return 0;
}