// Basic calculator
#include<bits/stdc++.h>
 
using namespace std ;

int sol(string s){
    stringstream ss(s);
    string token ;
    vector<string>str ;

    while(ss >> token){
        str.push_back(token);
    }
    stack<int>st;
    for(int i=0;i<str.size();i++){
        
    }

}
 
int main(){

    string s =  "1 + 1";
    int ans = sol(s);
    cout << ans ;
    
    return 0;
}