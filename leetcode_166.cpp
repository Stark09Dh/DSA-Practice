// Fraction to Recurring decimal 

#include<bits/stdc++.h>
 
using namespace std ;
string fractionToDecimal(int num, int deno) {
    string ans = "";
    bool neg = false ; 
    if(num < 0 || deno < 0){
        neg = true  ;
    }
    num = abs(num) ;
    deno = abs(deno) ;
    if(num == 0) return to_string(0) ;
    int q = num / deno ;
    int r = num % deno ;
    ans += neg ? "-" : "" ;
    ans += to_string(q) ;

    if(r == 0) return ans ;

    ans += "." ;

    unordered_map<long long, int> remainderMap;
    
    while(r != 0){
        if(remainderMap.find(r) != remainderMap.end()){
            int repeatIndex = remainderMap[r];
            ans.insert(repeatIndex, "(");
            ans += ")";
            return ans;
        }
        remainderMap[r] = ans.length();

        r *= 10 ;
        q = r / deno ;
        ans += to_string(q) ;
        r = r % deno ;
    }
    
    return ans ;
}
 
int main(){
 
    int numerator = 93, denominator = 7;
    cout << fractionToDecimal(numerator , denominator) ;

    return 0;
}