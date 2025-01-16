#include<bits/stdc++.h>
 
using namespace std ;

bool isPrefixAndSuffix(string &str1, string &str2){
    // for prefix
    bool prefix = false ;
    int i = 0 , j = 0 ; 
    while(i<str1.size() && j < str2.size() &&str1[i] == str2[j]){
        i++;
        j++;
    }
    if(i == str1.size()){
        prefix = true ;
    }

    // for suffix
    bool suffix = false ;
    i = str1.size()-1 ;
    j = str2.size() -1 ;
    while(i>=0 && j>= 0 && str1[i] == str2[j]){
        i-- ;
        j-- ;
    }
    if(i < 0){
        suffix = true ;
    }

    return (suffix && prefix) ;

}

int countPrefixSuffixPairs(vector<string>& words) {
    int ans = 0 ;
    int n = words.size() ;

    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(isPrefixAndSuffix(words[i] , words[j])){
                ans++ ;
            }
        }
    }

    return ans ;
}
 
int main(){
    vector<string>words = {"pa","papa","ma","mama"};

    int ans = countPrefixSuffixPairs(words) ;

    cout << ans ;
    
    return 0;
}