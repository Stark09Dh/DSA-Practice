#include<bits/stdc++.h>
 
using namespace std ;

// using string stream

string sol(string &str){
    stringstream ss(str);
    string token = "";
    string result = "";
    while(ss >> token){
        result = token+" "+result;
    }
    return result.substr(0,result.length()-1);
}
 
string sol2(string &str){
    reverse(str.begin(),str.end());
    int i=0,l=0,r=0;
    int n = str.length();
    while(i<n){
        while(i<n && str[i] != ' '){
            str[r] = str[i];
            str[r++]  = str[i++];
        }
        if(l<r){
            reverse(str.begin()+l,str.begin()+r);
            str[r] = ' ';
            r++;

            l = r ;
        }
        i++;
    }
    str = str.substr(0,r-1);
    return str ;
}

int main(){
 
    string str = "the sky is blue";
    string ans = sol2(str);
    cout << ans ;
    return 0;
}