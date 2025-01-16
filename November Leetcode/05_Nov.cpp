#include<bits/stdc++.h>
 
using namespace std ;




int minChanges(string s) {
    int n = s.length() ;
    int changes = 0 ;
    char ch = s[0] ;
    int cnt = 0 ;
    for(int i= 0 ;i<n;i++){
        if(s[i] == ch){
            cnt++ ;
            continue;
        }
        if(cnt %2 == 0){
            cnt = 1 ;
        }
        else{
            changes++ ;
            cnt = 0 ;
        }

        ch = s[i] ;
    }
    return changes;
}
 
int main(){
 
    string s = "10010100000111001101011000000010110011" ;
    cout << minChanges(s);
    return 0;
}