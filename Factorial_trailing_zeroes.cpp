#include<bits/stdc++.h>
 
using namespace std ;


int trailingZeroes(int&n){
    int cnt = 0 ;
    while(n>0){
        n /= 5 ;
        cnt += n ;
    }
    return cnt ;
    
}
 
int main(){
 
    int n =  3;
    int zeroes = trailingZeroes(n);
    cout << zeroes ;
    
    return 0;
}