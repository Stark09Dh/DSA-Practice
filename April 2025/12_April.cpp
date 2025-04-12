#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    #define ll long long 
    ll k_palindrome = 0 ;
    unordered_set<ll> st ;
    vector<ll>fact ;
    void factorial(){
        fact[0] = 1 ;
        
        for(int i = 1 ; i <= 10 ; i++){
            fact[i] = i*fact[i-1] ;
        }
    }
    ll countAllPermutation(vector<ll>&freq , int n){
        ll count = fact[n] ;
        for(int i = 0 ; i <= 9 ; i++){
            count /= fact[freq[i]] ;
        }
        return count ;
    }
    ll allArrangement(string number , int n){
        sort(number.begin() , number.end()) ;
        if(st.count(stoll(number))) return 0 ;

        st.insert(stoll(number)) ;

        vector<ll>freq(10) ;
        for(char c : number){
            freq[c-'0']++;
        }

        ll total_permutation = countAllPermutation(freq , n);
        ll invalid_permutation = 0 ;
        if(freq[0] > 0){
            freq[0]--;
            invalid_permutation = countAllPermutation(freq,n-1) ;
        }
        return total_permutation - invalid_permutation ;

    }

    bool isKPalindrome(string &number , int &k){
        return (stoll(number) %k == 0) ;
    }

    void generatePalindrome(int pos , int &n ,string &number , int &k){
        if(pos >= (n+1)/2){
            if(isKPalindrome(number ,k)){
                k_palindrome += allArrangement(number,n) ;
            }
            return ;
        }

        char start = pos==0 ? '1' : '0' ;
        while( start <= '9'){
            number[pos] = start ;
            number[n-pos-1] = start ;
            generatePalindrome(pos+1 ,n ,number , k);
            start++ ;
        }
        number[pos] = ' ' ;
    }

    long long countGoodIntegers(int n, int k) {
        k_palindrome = 0 ;
        st.clear();
        fact.resize(11) ;
        factorial();
        string number(n,' ') ;
        generatePalindrome(0,n,number ,k) ;
        return k_palindrome ;
    }

 
};
int main(){
 
    Solution sol ;
    int n = 3 , k = 5 ;
    cout << sol.countGoodIntegers(n,k) ;
    
    return 0;
}