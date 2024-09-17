#include<bits/stdc++.h>
 
using namespace std ;

vector<string> stringTovec(string str){
    stringstream ss(str) ;
    vector<string> res ;

    string word ;

    while(ss >> word){
        res.push_back(word) ;
    }

    return res ;
}

vector<string> uncommonFromSentences(string s1, string s2) {
    
    vector<string> str1 = stringTovec(s1);
    vector<string> str2 = stringTovec(s2) ;

    unordered_map<string,int>mp1 ;
    unordered_map<string,int>mp2 ; 

    vector<string> ans ;

    for(auto it : str1){
        mp1[it]++ ;
    }
    for(auto it : str2){
        mp2[it]++ ;
    }

    for(auto it : str1){
        if(mp1[it] == 1 && mp2.find(it) == mp2.end()){
            ans.push_back(it);
        }
    }
    for(auto it : str2){
        if(mp2[it] == 1 && mp1.find(it) == mp1.end()){
            ans.push_back(it);
        }
    }

    return ans ;
  
}
 
int main(){
 
    string s1 = "apple apple" ;
    string s2 = "banana" ;

    vector<string> ans = uncommonFromSentences(s1,s2);
    for(string &s : ans){
        cout << s << " ";
    }
    return 0;
}