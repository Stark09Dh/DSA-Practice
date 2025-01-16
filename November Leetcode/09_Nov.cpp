#include<bits/stdc++.h>
 
using namespace std ;
long long minEnd(int n , int x){
    long long res = x ;

    for(int i=1;i<n;i++){
        res = (res+1) | x ;
    }

    return res ;
}
 
int main(){
 
    int n= 4 , x = 2 ;
    cout << minEnd(n , x );
    return 0;
}