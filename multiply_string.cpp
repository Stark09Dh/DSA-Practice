#include<bits/stdc++.h>
 
using namespace std ;

// Naive Approach, doesn't handle num.length > 10 




int stringTonum(string s){
    int num = 0 ;
    for(int i=0;i<s.length();i++){
        num = num*10 + (s[i]-'0');
    }
    return num ;
}

string multiply2(string num1, string num2) {
    int n1 = stringTonum(num1);
    int n2 = stringTonum(num2) ;

    int mult = n1*n2 ;

    string res = "";
    while(mult > 0){
        int digit = mult % 10 ;
        mult /= 10 ;
        res += to_string(digit);
    }
    reverse(res.begin(),res.end());
    return res ;
}







// optimal Approach 
string multiply(string num1, string num2){
    if(num1 == "0" || num2 == "0") return "0" ;

    vector<int> res (num1.length() + num2.length() , 0) ;

    for(int i=num1.length()-1 ; i>=0 ; i--){
        for(int j = num2.length() ; j >= 0 ; j--){
            res[ i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            res[i+j] += res[i+j+1] / 10 ;
            res[i+j+1] %= 10 ;

        }
    }

    int i=0;
    while(i < res.size() && res[i] == 0) i++ ;

    string ans = "";

    while( i < res.size()) {
        ans.push_back(res[i]+'0');
        i++ ;
    }
    return ans ;
}

 
int main(){
 
    string n1 = "123" ;
    string n2 = "456" ;
    string ans = multiply(n1,n2);
    cout << ans ;
    return 0;
}

