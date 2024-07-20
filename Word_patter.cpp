#include<bits/stdc++.h>
 
using namespace std ;

bool sol(string &pat, string &str){
    vector<string>words;

    stringstream ss(str);
    
    string token ;
    int len = 0 ;
    while(getline(ss,token,' ')){
        words.push_back(token);
        len++;
    }
    int n= pat.length();
    if(n != len) return false ;

    unordered_map<string,char>mp;
    set<char>st ;

    for(int i=0;i<n;i++){
        string word = words[i];
        char ch = pat[i];
        if(mp.find(word) == mp.end() && st.find(ch) == st.end()){
            st.insert(ch);
            mp[word] = ch ;
        }
        else if(mp[word] != pat[i]){
            return false ;
        }
    }
    return true ;
}
 
int main(){
 
    string pattern = "abba";
    string str = "dog cat cat fish";
    bool ans = sol(pattern,str);
    cout << ans ;
    return 0;
}