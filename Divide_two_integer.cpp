#include<bits/stdc++.h>
 
using namespace std ;

int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1 ;

    bool sign  = true ;

    if(dividend >= 0 && divisor < 0) sign = false ;
    if(dividend < 0 && divisor >= 0) sign = false ;

    unsigned int n = abs(dividend);
    unsigned int d = abs(divisor);
    unsigned int ans = 0 ;
    while( n >= d){
        short count = 0 ;
        while(n > (d << (count+1))){
            count++ ;
        }
        ans += (1 << count) ;
        n = n - (d * (1<<count)) ;
    }
    if(ans == (1<<31) && sign) return INT_MAX;

    return (sign?(ans):(-1*(ans)));
}
 
int main(){
 
    int dividend = 10 ;
    int divisor = 3 ;
    int ans = divide(dividend,divisor);
    cout << ans ;
    return 0;
}