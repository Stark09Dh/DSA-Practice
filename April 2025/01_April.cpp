#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int n ;
    long long sol(int i , vector<vector<int>>&questions , vector<long long> &dp){
        if( i >= n) return LLONG_MIN ;

        if(dp[i] != -1) return dp[i] ;

        long long take = questions[i][0] ;
        if((i + questions[i][1] + 1 ) < n) {
            take += sol(i + questions[i][1] + 1 , questions , dp) ;
        }
        long long not_take = 0 + sol( i+1 , questions , dp) ;

        return dp[i] = max( take , not_take) ;
    }


    long long mostPoints(vector<vector<int>>& questions){
        n = questions.size() ;
        vector<long long> dp(n, -1) ;
        return sol(0 , questions , dp) ; 
    }
 
};
int main(){
 
    Solution sol ;
    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    cout << sol.mostPoints(questions) ;
    return 0;
}