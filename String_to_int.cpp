#include<bits/stdc++.h>
 
using namespace std ;

int myAtoi(string &s){
    int num =0 ;
    int n = s.size();
    int i = 0 ;
    if(!isdigit(s[i])) return  0 ;
    while(isspace(s[i])){
        i++  ;
    }
    bool sign = false;
    if(s[i] == '-'){
        sign = true ; ;
    }
    
    while(i<n && isdigit(s[i])){
        
        
        num = num*10 + (s[i]-'0') ;

        
        i++ ;

    }

    return sign ? -num : num ;
    
    
}
 
int main(){
 
    string s = "1337cd";
    int ans = myAtoi(s);

    cout  << ans ;
    return 0;
}