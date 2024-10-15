#include<bits/stdc++.h>
 
using namespace std ;

long long minimumSteps(string s) {
    int n = s.length();
    int len = n-1 , swaps = 0  ;

    for(int i= n-1 ; i>=0 ;i--){
        if(s[i] == '1'){
            swaps += len - i ;
            len-- ;
        }
    }

    return swaps ;
}
 
int main(){
 
    string s = "0111" ;
    cout <<  minimumSteps(s);
    return 0;
}