#include<bits/stdc++.h>
 
using namespace std ;

// TC = O((n - m + 1) * (g + sqrt(n)))

bool isPrime(int n) {
    if (n <= 1) return false;  
    if (n == 2) return true;   
    if (n % 2 == 0) return false; 

    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}



static pair<long long, long long> gap(int g, long long m, long long n) {
    long long first = 0 , second = 0 ;
    long long i = m ;
    while(i<=n){
        if(isPrime(i)){
            first = i ;
            bool in_btw = false ;
            for(long long j = i+1 ; j < i+g ; j++){
                if(isPrime(j) ){
                    in_btw = true ;
                    break ;
                }  
            } 
            if(in_btw == false && i+g <= n){
                if(isPrime(i+g)){
                    second = i+g ;
                    return make_pair(first , second) ;
                }
            }
        }
        i++ ;
    }
    if(second == 0) return make_pair(0,0) ;
    
    return make_pair(first, second) ;

}
 
int main(){
 
    int g = 10 ;
    long long start = 300 ;
    long long end = 400 ;
    pair<long long ,long long>ans = gap(g , start , end) ;
    cout  <<"{"<< ans.first << " " << ans.second <<"}"<< endl;

    return 0;
}