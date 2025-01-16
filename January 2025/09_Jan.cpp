#include<bits/stdc++.h>
 
using namespace std ;

int prefixCount(vector<string>& words, string pref) {
    int n = words.size() ;
    int m = pref.length() ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(words[i].length() > m){
            string prefix = words[i].substr(0,m);
            if(prefix == pref){
                ans++ ;
            }
        }
    } 
    return ans ;   
}
 
int main(){
 
    vector<string>  words = {"pay","attention","practice","attend"} ;
    string pref = "at" ;
    int ans = prefixCount(words , pref) ;
    cout << ans ;
    return 0;
}