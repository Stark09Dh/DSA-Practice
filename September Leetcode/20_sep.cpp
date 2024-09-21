#include<bits/stdc++.h>
 
using namespace std ;

// Brute froce TC : O(n*n) SC : O(n);

string shortestPalindrome2(string s){
    string rev = s ;
    reverse(rev.begin(),rev.end());
    int n = s.length();

    for(int i=0;i<n;i++){
        if(s.substr(0,n-i) == rev.substr(i)){ //compiler creates new string every time to compare which exceeds memory limit insteaad use 
            return rev.substr(0,i)+s ; //       memcmp to avoid it
        }
    }
    return rev + s;
}
string shortestPalindrome3(string s){
    string rev = s ;
    reverse(rev.begin(),rev.end());
    int n = s.length();

    for(int i=0;i<n;i++){
        if(!memcmp(s.c_str(),rev.c_str()+i , n-i)){ 
            return rev.substr(0,i)+s ; //       memcmp to avoid it. it just compare the strings without creating new string
        }
    }
    return rev + s;
}

string shortestPalindrome(string s) {
        
}
 
int main(){
 
    string s = "aacecaaa";
    string ans = shortestPalindrome3(s);
    cout << ans ;
    return 0;
}