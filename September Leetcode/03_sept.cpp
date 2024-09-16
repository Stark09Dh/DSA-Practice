#include<bits/stdc++.h>
 
using namespace std ;

int getLucky(string s, int k) {
    string num = "";
    for(char ch : s){
        int val = ch - 'a' + 1 ;
        num += to_string(val) ;
        
    } 
    int sum = 0 ; 
    for(char m : num){
        sum += m-'0' ;
    }

    k -= 1 ;

    while(k>0){
        int ans = 0 ;
        while(sum > 0 ){
            ans += sum % 10 ;
            sum /= 10 ;
        }
        sum = ans ;
        k-- ;
    }

    return sum  ;

}
 
int main(){
 
    string s = "leetcode";
    int k = 2 ;
    int ans = getLucky(s,k);
    cout << ans ;
    return 0;
}