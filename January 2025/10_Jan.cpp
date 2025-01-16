#include<bits/stdc++.h>
 
using namespace std ;

bool isSubset(vector<int>&hash2 , vector<int>&hash1){
    for(int i = 0 ; i < 26 ; i++){
        if(hash1[i] < hash2[i]){
            return false ;
        }
    }
    return true  ;
}

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int>hash2(26) ;
    vector<string> ans ;
    for(string & s : words2){
        vector<int>temp(26,0);
        for(char &ch : s){
            temp[ch-'a']++ ;

            hash2[ch-'a'] = max(hash2[ch-'a'] , temp[ch-'a']) ;
        }
    }
    for(int i = 0 ; i < words1.size() ; i++){
        vector<int>hash1(26,0) ;
        for( char &ch : words1[i]){
            hash1[ch-'a']++ ;
        }
        if(isSubset(hash2 , hash1)){
            ans.push_back(words1[i]) ;
        }
    }  
    return ans ; 
}
 
int main(){
 
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"} ;
    vector<string> words2 = {"e","o"} ;

    vector<string> ans = wordSubsets(words1 , words2) ;

    for(string &s : ans) {
        cout << s << " " ;
    }


    return 0;
}