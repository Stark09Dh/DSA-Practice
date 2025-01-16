#include<bits/stdc++.h>
 
using namespace std ;

string compressedString(string word) {
    string comp = "" ;
    int i = 0 ;

    while(i < word.length()){
        char ch = word[i] ;
        int cnt = 0 ;
        while(word[i] == ch && cnt < 9){
            i++ ;
            cnt++ ;
        }
        comp += to_string(cnt) + ch;
    }
    
    return comp ;
}
 
int main(){
 
    string word = "x" ;
    cout <<  compressedString(word) ;
    return 0;
}