#include<bits/stdc++.h>
 
using namespace std ;

int findTheWinner(int n, int k) {
        vector<int>hash(n+1) ;
        hash[0] = 0 ;
        for(int i = 1 ;i<hash.size();i++){
            hash[i] = 1 ;
        }
        int count = 0 ;
        int sum = n ;
        int i = 1 ;
        while(sum != 1){
            if(hash[i] == 1){
                count++;
            }
            if(count == k){
                sum--;
                hash[i] = 0 ;
                // i = i+1 ;
                count = 0 ;
            }
            i++ ;
            if(i==n+1){
                i = i % n ;
            }
            
        }
        int ans = -1 ;
        for(int i=0;i<hash.size();i++){
            if(hash[i] == 1) ans = i ;
        }
        return ans ;
    }
 
int main(){
 
    int n= 6 ;
    int k = 5 ;
    
    int ans = findTheWinner(n,k);
    cout << ans ;
    return 0;
}