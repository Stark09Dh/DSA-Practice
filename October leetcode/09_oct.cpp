#include<bits/stdc++.h>
 
using namespace std ;


// using stack SC : O(n) ;

int minAddToMakeValid2(string s) {
    stack<char>st ;
    
    for(char c : s){
        if(!st.empty() && (c ==')' && st.top()=='(') ){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    return st.size() ;    
}

// SC : O(1) ;

int minAddToMakeValid(string s) {
    int open = 0 , close = 0 ;

    for(char &c : s){
        if(c=='('){
            open++ ;
        }
        else if(c ==')'){
            if(open > 0 ){
                open-- ;
            }
            else{
                close++ ;
            }
        }
    }  

    return open+close ;  
}


 
int main(){
    string s = "()))((";
    cout << minAddToMakeValid(s);

    
    return 0;
}