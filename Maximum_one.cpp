#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&arr,int n){
    int ans = 0 ;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1 ){
            sum += 1;
        }
        else{
            ans = max(sum,ans);
            sum = 0;
        }
    }
    ans = max(sum, ans);
    return ans ;
}

 
int main(){
    int n = 8 ;
    vector<int>arr = {0,1,1,0,0,1,1,1};
    int ans = sol(arr,n);
    cout << ans ; 
    
    return 0;
}