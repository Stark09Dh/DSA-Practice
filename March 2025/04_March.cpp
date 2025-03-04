#include<bits/stdc++.h>
 
using namespace std ;

string dectotri(int x){
    string s = "" ;
    while( x > 0 ){
        int digit = x % 3 ;
        x /= 3 ;
        s += to_string(digit) ;
    }
    reverse(s.begin() , s.end()) ;
    return s ;
}

bool checkPowerOfThree(int n){
    string s = dectotri(n) ;
        for(char ch : s){
            if(ch =='2'){
                return false ;
            }
        }
        return true ;
}
 
int main(){
 
    int n = 91 ;
    cout << checkPowerOfThree(n) ;
    return 0;
}