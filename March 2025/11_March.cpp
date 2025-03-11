#include<bits/stdc++.h>
 
using namespace std ;

int numberOfSubstrings(string s) {
    int n = s.length() ;
    int l = 0 ,r = 0;
    int ans = 0 ;
    unordered_map<char , int> mp ;
    
    while( r < n ){
        char ch = s[r] ;
        mp[ch]++ ;
        while(mp.size() == 3 ){
            ans += (n-r) ;
            mp[s[l]]--;
            if(mp[s[l]] == 0) mp.erase(s[l]) ;
            l++;

        }
        r++ ;  
    }
    return ans ;
}
 
int main(){
 
    string s = "aaabc" ;
    cout <<  numberOfSubstrings(s) ;

    return 0;
}