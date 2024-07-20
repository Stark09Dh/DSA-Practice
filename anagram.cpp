#include<bits/stdc++.h>
 
using namespace std ;

bool sol(string &s,string &t){
    if(s.length() != t.length()) return false ;

    vector<char>hash(256,-1);
    for(int i=0;i<s.length();i++){
        hash[s[i]]++;
    }

    for(int j=0;j<t.length();j++){
        if(t[j] == hash[s[j]]){
            hash[s[j]]--;
        }
        else if(hash[t[j]] == -1) return false;
    }
    return true ;
}
 
int main(){
 
    string s = "eat";
    string t = "ate";
    bool ans = sol(s,t);
    cout << ans ;
    return 0;
}