// length of last word 

#include<bits/stdc++.h>
using namespace std ;

int sol(string &s){
    int n = s.length();
    int res = 0 ;
    for(int i=n-1;i>=0;i--){
        if(res != 0 && isspace(s[i])) break ;

        else if (isspace(s[i])){
            continue;
        }
        else if(!isspace(s[i])){
            res += 1;
        }
    }
    return res ;
}

 
int main(){
 
    string s = "luffy is still joyboy";
    int ans = sol(s);
    cout << ans ;
    
    return 0;
}