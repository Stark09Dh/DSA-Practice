#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    const int mod = 1e9 + 7 ;
    int countGoodNumbers(long long n) {
        long long count = 1 ;
        if(n % 2 == 0){
            count = (count * power(5 ,n/2) * power(4 , n/2)) % mod ;
        }
        else {
            count = (count * power(5 , (n/2) +1) * power(4 , n/2)) % mod ;
        }

        return count % mod ;
    }

    long long power(long long a , long long b){
        if( b== 0) return 1 ;
        long long half = (power(a , b/2))% mod ;
        long long res =( half * half) % mod ;
        if( b % 2 == 1 ){
            res = (res * a) % mod ;
        }
        return res % mod ;

    }
 
};
int main(){
 
    Solution sol ;
    long long n = 50 ;
    cout << sol.countGoodNumbers(n) ;
    
    return 0;
}