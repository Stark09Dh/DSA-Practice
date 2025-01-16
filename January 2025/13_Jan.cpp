#include<bits/stdc++.h>
 
using namespace std ;

int minimumLength(string s) {
    int n = s.length();
    string temp = s ;
    if(n <=2) return n;

    vector<int>freq(26,0) ;

    for(char &ch : s){
        freq[ch-'a']++ ;
    }

    for(int &i : freq ){
        while(i>2){
            i = i-2 ;
            n -= 2 ;
        }
    }
    
    return n; 
}
 
int main(){
 
    string s = "abaacbcbb" ;
    int ans = minimumLength(s) ; 
    cout <<  ans ;
    return 0;
}