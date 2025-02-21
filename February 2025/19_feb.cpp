#include<bits/stdc++.h>
 
using namespace std ;

vector<string> dotProduct(vector<string>first , vector<char>second){
    vector<string>res ;
    
    for(auto &str : first){
        for(auto &s : second){
            if(str.back() != s){
                res.push_back(str + s) ;
            }
        }
    }
    return res ;
}

string getHappyString(int n, int k) {
    vector<char>s = {'a','b','c'} ;
    if(n == 1){
        if(k <= 3) return to_string(s[k-1]);
        else return "" ;
    }
    vector<string>res = {"a","b","c"} ;
    for(int i = 1 ; i < n ; i++) {
        res = dotProduct(res , s) ;
    }
    // for(auto i : res ){
    //     cout << i << " " ;
    // }
    // cout << endl ;
    return (k >= res.size()) ? "" : res[k-1] ;


}
 
int main(){
 
    int n = 2 , k = 7 ;

    cout << getHappyString(n , k) ;

    // vector<string>a = {"a","b","c"};
    // vector<char>b = {'a','b','c'};

    // vector<string> ans = dotProduct(a,b );

    // for(auto i : ans ){
    //     cout << i << " " ;
    // }

    
    return 0;
}