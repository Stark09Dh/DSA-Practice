#include<bits/stdc++.h>
 
using namespace std ;

void sol(string beginWord, string endWord, vector<string>& wordList,set<string>&st, vector<string>&temp , vector<vector<string>>&ans ){
    if(beginWord == endWord){
        ans.push_back(temp) ;
    }

    for(int i=0;i<beginWord.length();i++){
        char org = beginWord[i] ;
        for(int j=0;j<26;j++){
            beginWord[i] = 'a' + j ;
            if(st.find(beginWord) != st.end()){
                temp.push_back(beginWord) ;
                st.erase(beginWord);
                sol(beginWord ,endWord,wordList , st,temp,ans) ;
                st.insert(beginWord) ;
                temp.pop_back();
            }
        }
        beginWord[i] = org ;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size() ;
    set<string>st ;
    vector<vector<string>>ans ;
    for(string s : wordList){
        st.insert(s);
    } 
    if(st.find(endWord) == st.end()) return {} ;

    vector<string>temp = {beginWord} ;

    sol(beginWord , endWord , wordList , st,temp,ans) ;

    return ans ;

}


vector<vector<string>> findLaddersDFS(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> st (wordList.begin() , wordList.end()) ;
    queue<vector<string>> q ;
    q.push({beginWord}) ;

    vector<string>usedOnLevel ;

    usedOnLevel.push_back(beginWord) ;
    int level = 0 ;
    vector<vector<string>>ans ;

    while(!q.empty()) {
        vector<string> vec = q.front() ;
        q.pop();
        if(vec.size() > level){
            level++ ;
            for(auto &it : usedOnLevel){
                st.erase(it) ;
            }
        }
        string word = vec.back() ;
        if(word == endWord){
            if(ans.size() == 0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec) ;
            }
        }
        for(int i =0 ;i<word.size();i++){
            char org = word[i] ;
            for(char c = 'a';c <='z';c++){
                word[i] = c ;
                if(st.count(word) > 0){
                    vec.push_back(word) ;
                    q.push(vec) ;
                    usedOnLevel.push_back(word);

                    vec.pop_back();
                }
            }
            word[i] = org ;
        }
    }
    return ans ;
}
 
int main(){
  
    string beginWord = "hit", endWord = "cog" ;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>>ans = findLaddersDFS(beginWord , endWord , wordList) ;

    for(vector<string> vec : ans){
        for(string s : vec){
            cout << s << " ";   
        }
        cout << endl;
    }

    return 0;
}