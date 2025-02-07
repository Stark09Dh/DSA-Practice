#include<bits/stdc++.h>
 
using namespace std ;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    int n = queries.size() ;
    vector<int>res ;
    unordered_map<int,int>hash;
    set<int>st ;
    unordered_map<int ,int>mp ;
    for(int i = 0 ; i < n ; i++){
        int ball = queries[i][0] ;
        int color = queries[i][1] ;
        if(hash.find(ball) == hash.end()){
            hash[ball] = color ;
            st.insert(color) ;
            mp[color]++ ;
        }
        else if(hash[ball] != color){
            int oldColor = hash[ball] ;
            mp[oldColor]--;

            if(mp[oldColor] == 0){
                st.erase(oldColor) ;
            }
            hash[ball] = color;
            mp[color]++;
            st.insert(color);
        }
        res.push_back(st.size()) ;
    }
    return res ;

}
 
int main(){
    int limit = 1;
    vector<vector<int>> queries = {{0,2},{1,10},{0,10},{0,3},{1,5}};
    vector<int>ans = queryResults(limit , queries) ;
    for(int &i :ans){
        cout << i <<" ";
    }
    return 0;
}