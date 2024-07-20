#include<bits/stdc++.h>

using namespace std ;

bool sol(vector<int>&arr,int n ){
    bool check = true ;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]) check = false ;
        
    }
    return check ;
    
}


int main(){
    int n = 5 ;
    vector<int>arr = {0,0,0,0,1};
    bool check = sol(arr,n);
    string ans = (check) ? "Yes" : "No" ;
    cout << ans ;
}
