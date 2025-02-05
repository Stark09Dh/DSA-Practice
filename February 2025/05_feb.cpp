#include<bits/stdc++.h>
 
using namespace std ;

bool areAlmostEqual(string s1, string s2) {
    vector<int>diff ;
    for(int i = 0 ; i < s1.length() ; i++){
        if(s1[i] != s2[i]) diff.push_back(i);
    }
    if(diff.size() == 1) return false ;

    if (diff.size() == 0) {
        return true;  
    }
    
    swap(s2[diff[0]],s2[diff[1]]);
    return s1 == s2 ;
}

int main(){
 
    string s1 = "abcd" , s2 = "dcba" ;
    int ans = areAlmostEqual(s1 , s2) ;
    cout <<  ans  ;
    return 0;
}