#include<bits/stdc++.h>
 
using namespace std ;

string sol(string s){
    string ans = "" ;
    ans.push_back(s[0]);
    int count = 1 ;
    for(int i = 1 ;i<s.length();i++){
        if(s[i] == ans.back()){
            count++ ;
            if(count < 3) ans.push_back(s[i]);
        }
        else{
            count = 1 ;
            ans.push_back(s[i]) ;
        }
    }
    return ans ;
}
 
int main(){
 
    string s = "aaabaaac" ;
    cout << sol(s) ;
    return 0;
}