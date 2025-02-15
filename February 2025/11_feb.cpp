#include<bits/stdc++.h>
 
using namespace std ;

string removeOccurrences(string s, string part) {
    
    while(true){
        int idx = s.find(part) ;

        if(idx == string::npos){
            break ;
        }
        s.erase(idx,part.length()) ;
    }
    return s ;
}
 
int main(){
 
    string s = "daabcbaabcbc", part = "abc" ;

    cout << removeOccurrences(s,part) ;

    return 0;
}