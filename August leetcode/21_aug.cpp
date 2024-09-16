#include<bits/stdc++.h>
 
using namespace std ;
int n ;
vector<vector<int>>dp ;
int solve(int l , int r , string &s){
    if(l==r) return 1 ;
    if(l > r) return 0 ;

    if(dp[l][r] != -1) return dp[l][r] ;

    int i = l+1 ;
    while(i <=r && s[i] == s[l]){
        i++ ;
    }
    if(i == r+1) return 1 ;

    int basic = 1+solve(i,r,s);

    int optmal = INT_MAX ;
    for(int j=i ; j<=r ; j++){
        if(s[j] == s[l]){
            int ans = solve(i,j-1,s) + solve(j,r,s);
            optmal = min(optmal,ans);

        }
    }

    return dp[l][r] =  min(optmal,basic) ;
}

int strangePrinter(string s) {
    n = s.length();
    dp.resize(n+1,vector<int>(n+1,-1));
    return solve(0,n-1,s);
}
 
int main(){
 
    string s = "aba" ;
    int ans = strangePrinter(s);
    cout << ans ;
    return 0;
}