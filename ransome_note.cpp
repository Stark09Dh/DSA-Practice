#include<bits/stdc++.h>
 
using namespace std ;

bool sol(string &m, string &r){
    int a = m.length();
    bool ans = true ;
    vector<int>hash(256,0);
    for(int i=0;i<a;i++){
        hash[m[i]]++;
    }
    for (char c : r) {
        if (hash[c] > 0) {
            hash[c]--;
        } else {
            return false;
        }
    }
    
    return ans;
    
}
 
int main(){
 
    string m = "aab";
    string r = "aa";
    bool ans = sol(m,r);
    cout<< ans ;
    return 0;
}