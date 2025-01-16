#include<bits/stdc++.h>
 
using namespace std ;

int calculate(string s) {
    stack<int>st ;
    int n = s.length() ;
    char sign = '+' ;

    for(int i =0 ; i < n ; i++){
        char ch = s[i] ;
        if(isdigit(ch)){
            int val = 0 ;
            while(i < n && isdigit(s[i])){
                val = val * 10 + (s[i]-'0') ;
                i++ ;
            }
            i-- ;
            if(sign == '+'){
                st.push(val) ;
            }
            else if(sign=='-'){
                st.push(-val) ;
            }
            else if(sign == '*'){
                int a = st.top();
                st.pop() ;
                int ans = a * val ;
                st.push(ans);
            }
            else if(sign == '/'){
                int a = st.top() ;
                st.pop() ;
                int ans =  a / val ;
                st.push(ans) ; 
            }
        }
        else if(ch != ' '){
            sign = ch ;
        }
    }
    int ans = 0  ;

    while(!st.empty()){
        ans += st.top() ;
        st.pop() ;
    }
    return ans ;
}
 
int main(){
 
    string s = "3+2*2" ;

    cout << calculate(s) ;

    return 0;
}