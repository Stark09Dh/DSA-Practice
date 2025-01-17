// Generate all the permutation of the given string exclude the duplicates 

#include<bits/stdc++.h>
 
using namespace std ;

void help(int idx , string &s , unordered_set<string>&st){
    if(idx >= s.size()) {
        st.insert(s) ;
        return ;
    }

    for(int j = idx ; j < s.size() ; j++){
        swap(s[idx] , s[j]) ;
        help(idx+1 , s , st) ;
        swap(s[idx] , s[j]) ;
    }
    
    
}

vector<string> permutations(string s) {
    
    int n = s.length();

    unordered_set<string> st ;

    help(0 , s , st) ;

    return vector<string>(st.begin() , st.end()) ;
  
}
 
int main(){
    
    string s = "abc" ;
    vector<string> ans = permutations(s) ;

    cout << '[' ;
    for(string &s : ans){
        cout << "\"" << s << "\"" ;
    }
    cout<<']' ;

    
    
    return 0;
}