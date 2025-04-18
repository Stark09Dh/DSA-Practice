#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    const int MOD = 1e9 + 7 ;

    long long findPower(long long a , long long b){
        if(b == 0) return 1 ;
        long long half = findPower(a , b/2) ;
        long long res = ( half * half ) % MOD ;
        if(b % 2 == 1){
            res = ( res * a ) % MOD ;
        }
        return res ;
    }

    vector<int> getPrimes(int limit){
        vector<bool>isPrime(limit +1 , true) ;
        vector<int>primes ;

        for(int i = 2 ; i <= limit ; i++){
            if(isPrime[i]){
                for(int j = i*i ; j <= limit ; j+= i){
                    isPrime[j] = false ;
                }
            }
        }

        for(int i = 2 ; i <= limit ; i++){
            if(isPrime[i]){
                primes.push_back(i) ;
            }
        }
        return primes ;
    }

    vector<int>findPrimeScore(vector<int>&nums){
        int n = nums.size() ;
        vector<int>primescore(n,0) ;
        int maxElement = *max_element(nums.begin() , nums.end()) ;
        vector<int>primes = getPrimes(maxElement) ;

        for(int i = 0 ; i < n ; i++){
            int num = nums[i] ;

            for(int prime : primes) {
                if(prime * prime > num){
                    break ;
                }
                if(num % prime != 0) continue;
                primescore[i]++ ;
                while(num % prime == 0){
                    num /= prime ;
                }
            }
            if(num > 1) {
                primescore[i]++ ;
            }

        }
        return primescore ;
    }

    vector<int>findNextGreater(vector<int>&primeScores){
        int n = primeScores.size() ;
        vector<int>nextGreater(n) ;
        stack<int>st ;

        for(int i = n-1 ; i >=0 ; i--){
            while(!st.empty() && primeScores[st.top()] <= primeScores[i]){
                st.pop() ;
            }

            nextGreater[i] = st.empty() ? n : st.top() ;
            st.push(i) ; 
        }

        return nextGreater ;
    }  

    vector<int>findPrevGreater(vector<int>&primeScores){
        int n = primeScores.size() ;
        vector<int>prevGreater(n) ;
        stack<int>st ;

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && primeScores[st.top()] < primeScores[i]){
                st.pop() ;
            }

            prevGreater[i] = st.empty() ? -1 : st.top() ;
            st.push(i) ; 
        }

        return prevGreater ;
    }  

    int maximumScore(vector<int>& nums, int k) {
        vector<int>primeScores = findPrimeScore(nums) ;
        vector<int>nextGreater = findNextGreater(primeScores) ;  
        vector<int>prevGreater = findPrevGreater(primeScores) ; 
        
        int n = nums.size() ;
        vector<long long> subarray(n,0);

        for(int i = 0 ; i < n ; i++){
            subarray[i] = (long long)(nextGreater[i] - i) * ( i- prevGreater[i]) ;
        }

        vector<pair<int,int>>sortedNums(n) ;
        for(int i = 0 ; i  < n ; i++){
            sortedNums[i] = {nums[i],i} ;
        }
        sort(sortedNums.begin() , sortedNums.end(), greater<>()) ;

        long long score = 1 ;

        int idx = 0 ;

        while(k > 0){
            auto [num,i] = sortedNums[idx] ;
            long long operation = min((long long)k ,subarray[i]);

            score = (score* findPower(num , operation)) % MOD ;

            k = k - operation ;
            idx++ ;
        }

        return score ;
    }
 
};
int main(){
 
    Solution sol ;
    int k = 3 ;
    vector<int>nums = {19,12,14,6,10,18} ;
    cout << sol.maximumScore(nums , k) ;
    
    return 0;
}