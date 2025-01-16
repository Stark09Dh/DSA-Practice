#include<bits/stdc++.h>
 
using namespace std ;

int partitionString(string s) {
    int n = s.length() ;
    vector<int>hash(26,-1) ;

    int start = 0 ;
    int ans = 0 ;

    for(int i=0;i<n;i++){
        char ch = s[i] ;
        if(hash[ch - 'a'] >= start){
            ans++;
            start = i ;
        }
        hash[ch-'a'] = i ;
    }
    return ans + 1 ;
}
 
int main(){
 
    string s = "abacaba" ;
    cout << partitionString(s) ;
    return 0;
}