#include<bits/stdc++.h>
 
using namespace std ;

bool isSubsequence(string &t, string &s){
    int n =t.length();
    int m = s.length();
    int i=0,j=0;
    while( i < n && j < m){
        if(t[i] != s[j]){
            i++;
        }
        else{
            j++;
            i++;
        }
    }
    bool ans =0;
    if(j==m) ans = 1 ;
    return ans ;
}
 
int main(){
 
    string t = "ahbgdc";
    string s = "abc";
    bool ans = isSubsequence(t,s);
    cout << ans ;
    return 0;
}