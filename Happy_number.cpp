#include<bits/stdc++.h>
 
using namespace std ;

int calc(int n){
    if(n==1) return n;
    int sum = 0 ;
    while(n){
        int n1 = n%10;
        sum += n1*n1;
        n /= 10 ;
    }
    return sum ;


}

bool sol(int n){
    unordered_map<int,int>mp;
    if(n ==1) return true ;
    while(mp.find(n) == mp.end()){
        mp[n]++;
        n = calc(n);
    }
    if(n ==1) return true ;
    return false ;
}
 
int main(){
 
    int n = 2 ;
    bool ans = sol(n); 
    cout << ans ;
    return 0;
}