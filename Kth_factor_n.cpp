#include<bits/stdc++.h>
 
using namespace std ;

int kthFactor(int n, int k) {
    int count  = 0 ;

    for(int i= 1; i<=n ; i++){
        if(n % i == 0){
            count++ ;
            
        }
        if(count == k){
            return i ;
        }
    }
    return -1 ;

}
 
int main(){
 
    int n = 7 , k = 2 ;
    cout << kthFactor(n , k );
    return 0;
}