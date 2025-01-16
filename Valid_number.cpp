#include<bits/stdc++.h>
 
using namespace std ;

/*
digit
plus minus
dot 
e/E


*/

bool isNumber(string s) {
    int n = s.length() ;
    bool digit = false , dotseen = false , eseen = false ;
    int signCount  = 0 ;
    for(int i=0;i<n;i++){
        char ch = s[i] ;
        // sign '+ || '-'
        if(isdigit(ch)){
            digit = true; 
        }

        else if(ch =='+' || ch == '-'){
            if(signCount == 2) return false;

            if(i>0 && (s[i-1] != 'e' && s[i-1] != 'E')){
                return false ;
            }

            if(i == n-1) return false ;

            signCount++ ;
        }

        else if(ch == '.'){
            if(eseen || dotseen) return false ;

            if(i == n-1 && !digit) return  false ;

            dotseen = true ;
        }

        else if(ch == 'e' || ch == 'E'){
            if(eseen || !digit || i == n-1){
                return false ;
            }
            eseen = true ;
        }

        else{
            return false ;
        }
    } 


    return true ; 
}
 
int main(){
 
    string s = ".9" ;
    cout << isNumber(s) ;
    return 0;
}