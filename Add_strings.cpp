#include<bits/stdc++.h>
 
using namespace std ;

string addStrings(string num1, string num2) {
    string ans;  
    int n = num1.length() , m = num2.length() ;  
    int i=n-1,j=m-1;
    int carry = 0 ;
    while(i>=0 || j >= 0 || carry > 0){
        int digit1 = i>=0 ?  num1[i]-'0' :0 ;
        int digit2 = j>=0 ?  num2[j]-'0' :0 ;
        int sum = digit1 + digit2 + carry ;
        carry = sum / 10 ;
        ans.push_back((sum %10)+'0');
        i-- , j-- ;
    }

    reverse(ans.begin() , ans.end()) ;
    return ans ;
    
}

 
int main(){
 
    string num1 = "11" , num2 = "123" ;
    
    cout << addStrings(num1,num2) ;

    return 0;
}