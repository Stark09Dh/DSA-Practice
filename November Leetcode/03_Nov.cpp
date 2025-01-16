#include<bits/stdc++.h>
 
using namespace std ;


 // TC : O(n*n)  SC : O(n*n)
bool rotateString(string s, string goal) {
    set<string>st ;
    int n = s.length() ;
    string temp  = s;

    for(int i = 0 ;i<n;i++){
        char c = temp[0] ;
        temp = temp.substr(1,n-1) ;
        temp.push_back(c) ;
        st.insert(temp) ;
    }
    
    return (st.find(goal) != st.end())? true : false  ;
}


// TC : O(n) SC : O(1) ;
bool rotateString2(string s , string goal){
    if(s == goal) return true ;
    s += s ;
    
    return s.find(goal) != string::npos ;
}


 
int main(){
 
    string s = "abcde", goal = "cdeab" ;
    


    cout << rotateString2(s,goal) ;
    return 0;
}

/*

s = abcde , goal = cdeab  
 'a' goes back become 'bcdea'
 'b' goes back become 'cdeab' , hence "true"

s = abcde , goal = abced
 'a' goes back become 'bcdea'
 'b' goes back become 'cdeab'
 'c' goes back become 'deabc'
 'd' goes back become 'eabcd'
 'e' goes back become 'abcde'

*/