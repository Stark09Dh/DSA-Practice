#include<bits/stdc++.h>
 
using namespace std ;

int countN (long curr , long next , int n){
    int countNum = 0 ;
    while(curr <= n){
        countNum += (next - curr) ;

        curr *= 10 ;
        next *= 10 ;
        next = min(next , long(n+1));
    }
    return countNum ;
}

int findKthNumber(int n, int k) {
    int curr = 1 ; 
    k-- ;   
    while(k>0){
        int count = countN(curr ,curr+1, n);
        if(count <= k){
            curr++ ;
            k -= count ;
        }
        else{
            curr *= 10 ;
            k--;
        }
    }
    return curr ;
}
 
int main(){
 
    int n = 13 , k = 2 ;
    int ans = findKthNumber(n,k);
    cout << ans ;
    return 0;
}