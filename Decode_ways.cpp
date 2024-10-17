// leetcode 91. Decode Ways 

#include<bits/stdc++.h>
 
using namespace std ;

int dfs(string &s, int i , unordered_map<int,int>&dp){
    if(dp.find(i) != dp.end()){
        return dp[i] ;
    }

    if(s[i] == '0'){
        return 0 ; // leading zero
    }

    int res = dfs(s,i+1,dp);

    if(i+1 < s.length() && (s[i] =='1' || (s[i]=='2' && s[i+1] <= '6'))){
        res += dfs(s,i+2 ,dp) ;
    }

    dp[i] = res ;
    return res ;
}

int numDecodings(string s) {
    unordered_map<int, int>dp;

    dp[s.length()] = 1 ;

    return dfs(s,0,dp) ;
}
 
int main(){
 
    string s = "121" ;

    cout << numDecodings(s) ;
    return 0;
}