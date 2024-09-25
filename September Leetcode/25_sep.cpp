#include<bits/stdc++.h>
 
using namespace std ;

struct TrieNode{
    int countP = 0 ;
    TrieNode* children[26] ;
};

TrieNode* getNode(){
    TrieNode* newNode = new TrieNode();
    for(int i=0;i<26;i++){
        newNode ->children[i] = NULL;
    }
    newNode->countP = 0 ;
    return newNode;
}

void insert(string &word,TrieNode* root){
    TrieNode* crawl = root ;
    for(char &ch: word){
        int idx = ch - 'a' ;
        if(!crawl -> children[idx]){
            crawl -> children[idx] = getNode();
        }

        crawl -> children[idx] ->countP += 1 ;
        crawl = crawl->children[idx];
    }
}

int getScore(string &word , TrieNode* root){
    TrieNode* crawl = root ;
    int score = 0 ;
    for(char &ch : word){
        int idx = ch - 'a' ;
        score  += crawl -> children[idx] ->countP ;
        crawl = crawl->children[idx];
    }
    return score ;
}


vector<int> sumPrefixScores(vector<string>& words) {
    int n = words.size();

    TrieNode* root = getNode();
    for(string &word : words){
        insert(word,root);
    }
    vector<int>result(n);
    for(int i=0;i<n;i++){
        result[i] = getScore(words[i],root);
    }
    return result ;
}
 
int main(){
 
    vector<string>words = {"abc","ab","bc","b"} ;
    vector<int> ans = sumPrefixScores(words) ;
    for(int &i : ans ){
        cout << i << " ";
    }
    return 0;
}