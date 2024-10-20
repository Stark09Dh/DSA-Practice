#include<bits/stdc++.h>
 
using namespace std ;


// Brute Force TC : O(2^n)
string invert(string s){

    string inverted = s;

    for(int i=0;i<s.length() ;i++){
        inverted[i] = (s[i] == '1') ? '0' : '1' ;
    }
    return inverted ;
}
string sol(int n ){
    if(n == 1){
        return "0" ;
    }
    string prev = sol(n-1) ;
    string invertS = invert(prev) ;
    reverse(invertS.begin(),invertS.end());

    return prev + "1" + invertS ;

}
char findKthBit(int n, int k) {
    string s = sol(n) ;
    return s[k-1] ;   
}

// Better Approach TC : O(n) 
char findKthBit2(int n, int k) {
    if(n == 1){
        return '0' ;
    }

    int len = (1 << n) -1 ;

    if(k < ceil(len/2.0)){
        return findKthBit(n-1 , k) ;
    }
    else if(k == ceil(len/ 2.0)){
        return '1' ;
    }
    else{
        char ch = findKthBit(n-1 , len-(k-1)) ;
        return (ch == '0') ? '1' : '0';
    }
}

 
int main(){
 
    int n = 4 , k = 11 ;

    cout << findKthBit(n,k) ;

    

    return 0;
}