#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&arr){
    int n = arr.size();
    vector<int>l2r(n,1);
    vector<int>r2l(n,1);

    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]){
            l2r[i] = max(l2r[i],l2r[i-1]+1);
        }
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i] > arr[i+1]){
            r2l[i] = max(r2l[i],r2l[i+11]+1);
        }
    }
    int result = 0 ;
    for(int i=0;i<n;i++){
        result += max(l2r[i],r2l[i]);
    }
    return result ;
}
 
int main(){
 
    vector<int>arr = {1,3,2,2,1};
    int ans = sol(arr);
    cout << ans << " ";
    return 0;
}