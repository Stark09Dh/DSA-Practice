#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    string countAndSay(int n){
        if(n == 1) return "1" ;
        string s = "1" ;
        for(int i = 2 ; i <= n ; i++){
            int count = 1 ;
            string temp = "" ;
            for(int  j = 0 ; j < s.length()-1 ; j++){
                if(s[j] == s[j+1]) count++;
                else{
                    temp += to_string(count) + s[j] ; 
                    count = 1 ;
                }
            }
            temp += to_string(count) + s.back();
            s = temp ;
        }
        return s;
    }
 
};
int main(){
 
    Solution sol ;
    int n = 7 ;
    cout << sol.countAndSay(n);
    
    return 0;
}