#include<bits/stdc++.h>
 
using namespace std ;

int solve(int i , string &s , unordered_set<string>&st,int n,vector<int>dp){
    if(i>=n) return 0 ;

    if(dp[i] != -1) return dp[i] ;

    int res = 1 + solve(i+1,s,st,n,dp);

    for(int j=i;j<n;j++){
        string str = s.substr(i,j-i+1); // slicing the string to find it in set 
        if(st.count(str)){ // present in set
            res = min(res , solve(j+1,s,st,n,dp));
        }
    }
    return dp[i] = res ;
}

// tabulation 
int minExtraChar2(string s, vector<string>& dict) {
    int n = s.length();
    unordered_set<string>st(dict.begin(),dict.end());
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        dp[i] = 1 + dp[i+1] ;
        for(int j=i;j<n;j++){
            string str = s.substr(i,j-i+1); // slicing the string to find it in set 
            if(st.count(str)){ // present in set
                dp[i] = min(dp[i] , dp[j+1]);
            }
        }
    }
    return dp[0] ;


}



int minExtraChar(string s, vector<string>& dict) {
    int n = s.length();
    unordered_set<string>st(dict.begin(),dict.end());
    vector<int>dp(n+1,-1);
    return solve(0,s,st,n,dp);

}
 
int main(){
 
    string s = "sayhelloworld";
    vector<string>dict = {"hello", "world"} ;

    int ans = minExtraChar2(s,dict) ;

    cout << ans ;
    return 0;
}