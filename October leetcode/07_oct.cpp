#include<bits/stdc++.h>
 
using namespace std ;

int minLength(string s) {
    int n  = s.length();
    stack<char>st ;
    for(int i=0;i<n;i++){
        if(!st.empty()&& ((st.top() == 'A' && s[i] == 'B') || (st.top() == 'C' && s[i] == 'D'))){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    return st.size();
}
 
int main(){
 
    string s = "ACBBD" ;
    cout << minLength(s);
    return 0;
}