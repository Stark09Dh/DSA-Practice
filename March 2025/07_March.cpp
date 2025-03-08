#include<bits/stdc++.h>
 
using namespace std ;

/*

left   <=  a  <  b   <=  right 

  b - a = x , x should minimum = 1,2,3,4,
  a = b + x ;

*/

bool isPrime(int n){
    if (n <= 1) return false; 
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false; 
    }
    return true;
}


// Brute Force TC = O(right-left)²
vector<int> closestPrimes(int left, int right) {
    unordered_set<int>st ;
    for(int i = left ; i <= right ; i++){
        if(isPrime(i)){
            st.insert(i) ;
        }
    }

    int first = INT_MAX ;
    int second = INT_MAX ;

    for(int i= left ; i <= right ; i++){
        if(isPrime(i)){
            for(int x = 1 ; x <= right - left ; x++){  
                int a = i + x ;
                if(st.find(a) != st.end() && a < first ){
                    first = a ;
                    second = i ;
                }
                
            }  
        }
    }

    if(first == INT_MAX && second == INT_MAX){
        return {-1 , -1 };
    }
    return {second, first} ;
}

/* More Optimization can be done using Sieve of Eratosthenes and binary search

    Sieve of Eratosthenes: The algorithm is very simple,at the beginning we write down all numbers between 2 and n .
     We mark all proper multiples of 2 (since 2 is the smallest prime number) as composite. 
     A proper multiple of a number x , is a number greater than  x and divisible by  x. 
     Then we find the next number that hasn't been marked as composite, in this case it is 3. 
     Which means 3 is prime, and we mark all proper multiples of 3 as composite. 
     The next unmarked number is 5, which is the next prime number, and we mark all proper multiples of it.
     And we continue this procedure until we have processed all numbers in the row.

*/

vector<bool>primes (int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime ;
}

vector<int> closestPrimes2(int left, int right) {
    vector<bool>prime = primes(right) ; 

    vector<int>need ;
    for(int i = left ; i <= right ; i++){
        if(prime[i]){
            need.push_back(i) ;
        }
    }

    int mindiff = INT_MAX ;
    pair<int, int > ans = {-1,-1} ;

    for(int i = 1 ; i < need.size() ; i++){
        int diff = need[i] - need[i-1] ;
        if( diff < mindiff){
            mindiff = diff ;
            ans = {need[i-1] , need[i]} ;
        }
    }
    return {ans.first , ans.second} ;
    
    
}



 
int main(){
 
    int left = 10 , right = 19 ;
    vector<int> ans = closestPrimes2(left , right ) ;
    cout << '[' << ans[0] <<','<<ans[1] <<']' ; 

    return 0;
}