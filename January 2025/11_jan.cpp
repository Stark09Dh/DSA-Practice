#include<bits/stdc++.h>
 
using namespace std ;

bool canConstruct(string s, int k) {
    if(s.length() < k) return false; 

    vector<int>freq(26) ;

    for(char &ch : s){
        freq[ch-'a']++ ;
    }  
    int odd_count = 0 ;

    for(int &i:freq){
        if(i%2 != 0 ){
            odd_count++ ;
        }
    }
    return (odd_count <= k) ? true : false ;
}
 
int main(){
 
    string s = "yzyzyzyzyzyzyzy" ;
    int k = 2 ;

    cout << (canConstruct(s,k)) ? "True" : "false" ;
    return 0;
}