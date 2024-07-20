// Longest Substring Without Repeating Characters
/*
Given a string s, find the length of the longest 
substring without repeating characters.
*/

#include<bits/stdc++.h>
 
using namespace std ;

int sol(string &s){
    int n = s.length();
    vector<int>hash(256,-1);
    int l = 0 , r = 0 ;
    int maxLen = 0 ;
    while(r < n){
        if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1 ;
            }
        }
        int len = r-l+1 ;
        maxLen = max(maxLen,len);
        hash[s[r]] = r;
        r++;
    }
    return maxLen;
}
 
int main(){
 
    string s = "pwwkew";
    int ans = sol(s);
    cout << ans ;
    return 0;
}