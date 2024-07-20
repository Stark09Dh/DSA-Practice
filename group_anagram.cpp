#include<bits/stdc++.h>
 
using namespace std ;

bool isvalid(string &s,string& t){
    if(s.length() != t.length()) return false ;

    vector<int>hash(256,-1);
    for(int i=0;i<s.length();i++){
        hash[s[i]]++;
    }
    for(int j=0;j<t.length();j++){
        if(t[j] == hash[s[j]]){
            hash[s[j]]--;
        }
        else if(hash[t[j]] == -1) return false;
    }
    return true ;
}
// not running for test case : {"","",""}
// expected : {{"","",""}} our {{"",""}}
vector<vector<string>>sol(vector<string>&str){
    unordered_map<string,int>mp;
    vector<vector<string>>ans ;
    for(int i=0;i<str.size();i++){
        string word = str[i];
        
        if(!mp.count(word)){
            vector<string>temp;
            temp.push_back(word);
            for(int j=i+1;j<str.size();j++){
                string word2 = str[j];
                if(!mp.count(word2)){
                    if(isvalid(word,word2)){
                        temp.push_back(word2);
                        mp[word2] = i ;
                    }
                }  
            } 
            ans.push_back(temp);  
        }
        mp[word] = i ; 
    }
    return ans ;
}

/*
if we sort any word which is anagram it become the same word 
e.g  eat , ate sort : aet, aet

*/

vector<vector<string>>sol2(vector<string>&str){
    int n= str.size();
    unordered_map<string,vector<string>>mp;
    vector<vector<string>>ans ;
    for(int i=0;i<n;i++){
        string temp = str[i];
        sort(begin(temp),end(temp));
        mp[temp].push_back(str[i]);
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
 
    vector<string>strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>ans = sol2(strs);

    for (int i = 0; i < ans.size(); i++)  
    { 
        for (int j = 0; j < ans[i].size(); j++) 
        { 
            cout << ans[i][j] << " "; 
        }     
        cout << endl; 
    } 
    return 0;
}