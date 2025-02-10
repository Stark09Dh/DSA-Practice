#include<bits/stdc++.h>
 
using namespace std ;

string clearDigits(string s) {
    int n = s.length() ;
    stack<char>st ;
    
    for(char &ch : s){
        if(isdigit(ch)){
            st.pop() ;
        }
        else{
            st.push(ch) ;
        }
    }
    
    string ans  = "";
    while(!st.empty()){
        ans =st.top() + ans;
        st.pop();
    }
    return ans ;
}
 
int main(){
 
    string s = "abc" ;
    cout << clearDigits(s) ;

    return 0;
}