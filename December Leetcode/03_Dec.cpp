#include<bits/stdc++.h>
 
using namespace std ;

string addSpaces(string s, vector<int>& spaces) {
    int n = spaces.size() ;
    int m = s.length();
    string ans;
    set<int>st(spaces.begin() , spaces.end()) ;

    for(int i = 0 ; i < s.length() ; i++){
        if(st.find(i) != st.end()){
            ans += ' '; 
        }
        ans += s[i] ;
        
    }
    return ans ;     
}
 
int main(){
 
    string s ="LeetcodeHelpsMeLearn" ;
    vector<int>spaces = {8,13,15} ;

    cout << addSpaces(s,spaces) ;
    return 0;
}