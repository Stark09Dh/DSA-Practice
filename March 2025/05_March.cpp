#include<bits/stdc++.h>
 
using namespace std ;

long long sol(int n , vector<long long>&dp){
    if(n == 2) return 5 ;

    if(dp[n] != -1) return dp[n] ;

    int digit = (n-1) * 4 ;

    return dp[n] = digit + sol(n-1 , dp) ;
}

long long coloredCells(int n) {
    vector<long long> dp(n+1, -1) ;
    dp[0] = 0 ;
    dp[1] = 1 ;
    if( n <= 1) return dp[n] ;

    return sol(n , dp) ;
} 
 
int main(){
 
    int n = 5 ;

    cout << coloredCells(n) ;

    return 0;
}