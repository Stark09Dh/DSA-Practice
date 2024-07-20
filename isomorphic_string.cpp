#include<bits/stdc++.h>
 
using namespace std ;

bool sol(string &s,string &t){
    unordered_map<char,char>mp_s;
    unordered_map<char,char>mp_t;
    for(int i=0;i<s.length();i++){
        if(mp_s.find(s[i]) == mp_s.end() && mp_t.find(t[i]) == mp_t.end()){
            mp_s[s[i]]=t[i];
            mp_t[t[i]] = s[i];
        }
        else if( t[i] != mp_s[s[i]] || s[i] != mp_t[t[i]]){
            return false;
        }
    }
    return true ;
}
 
int main(){
 
    string s = "badc";
    string t = "baba";
    bool ans = sol(s,t);
    cout << ans ;
    return 0;
}