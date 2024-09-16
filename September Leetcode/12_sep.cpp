#include<bits/stdc++.h>
 
using namespace std ;

int countConsistentStrings(string allowed, vector<string>& words) {
    set<char>st(allowed.begin(),allowed.end()) ;

    int n = st.size() ;

    int ans = 0 ;
    

    for(int i=0;i<words.size();i++){
        bool flag = true ;

        for( char c : words[i]){
            if(st.find(c) == st.end()){
                flag = false;
                break ;
            }
        }
        if(flag){
            ans++ ;
        }
    }
    return ans ;
}
 
int main(){
 
    string allowed = "abc" ;
    vector<string>words = {"a","b","c","ab","ac","bc","abc"} ;
    int ans = countConsistentStrings(allowed , words);
    cout << ans ;
    return 0;
}