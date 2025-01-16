#include<bits/stdc++.h>
 
using namespace std ;


// Brute Froce Gives TLE
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int qs = queries.size() ;
    vector<int>ans ;
    set<char>vowels = {'a' ,'e','i','o','u'} ;

    for(int i = 0 ; i < qs ; i++){
        int start = queries[i][0] ;
        int end = queries[i][1] ;
        int temp = 0 ;
        for(int j = start ; j <= end ; j++){
            int size  = words[j].size() ;
            if(vowels.count(words[j][0]) && vowels.count(words[j][size-1])){
                temp++ ;
            }   
            
        }
        ans.push_back(temp) ;
    }
    return ans ;

}

// Slightly Better Approach using prefix sum

vector<int> vowelStrings2(vector<string>& words, vector<vector<int>>& queries) {
    int qs = queries.size() ;
    vector<int>ans ;
    set<char>vowels = {'a' ,'e','i','o','u'} ;
    vector<int> prefixSum (words.size(),0);
    if(vowels.count(words[0][0]) && vowels.count(words[0][words[0].size()-1])){
        prefixSum[0] = 1 ;
    }
    for(int i = 1 ;i < words.size() ; i++){
        int size = words[i].size();
        if(vowels.count(words[i][0]) && vowels.count(words[i][size-1])){
            prefixSum[i] = prefixSum[i-1] + 1 ;
        }
        else{
            prefixSum[i] = prefixSum[i-1] ;
        }
    }

    for(int i = 0 ; i < qs ; i++){
        int start  = queries[i][0] ;
        int end = queries[i][1] ;
        int temp = prefixSum[end];
        if (start > 0) {
            temp -= prefixSum[start - 1];
        }
        ans.push_back(temp);
    }


    return ans;
}

 
int main(){
 
    vector<string> words = {"aba","bcb","ece","aa","e"} ;
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}} ;
    vector<int> ans  = vowelStrings2(words , queries) ;

    for(int &i : ans){
        cout << i << " ";
    }
    return 0;
}