#include<bits/stdc++.h>
 
using namespace std ;

bool dfs(int u , int v ,unordered_map<int , vector<int>>&adj, vector<bool>&visited){
    visited[u] = true ;

    if(u == v) return true ;

    for(auto nbr : adj[u]){
        if(visited[nbr]) continue ;

        if(dfs(nbr,v,adj,visited)){
            return true ;
        }
    }
    return false ;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size() ; 
    unordered_map<int , vector<int>>adj ;

    for(int i = 0 ; i < n ; i++){
        int u = edges[i][0];
        int v = edges[i][1] ;
        vector<bool>visited(n, false) ;

        if(adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(u , v ,adj , visited)){
            return edges[i] ;
        }

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }   
    return {};
}
 
int main(){
 
    vector<vector<int>>edges = {{1,2},{1,3},{2,3}} ;
    vector<int>ans = findRedundantConnection(edges) ;
    for(int &i: ans){
        cout << i << " ";
    }
    return 0;
}