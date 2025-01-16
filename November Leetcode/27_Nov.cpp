#include<bits/stdc++.h>
 
using namespace std ;

int bfs( int n , unordered_map<int  ,vector<int>>&adj ){
    queue<int>q ;
    q.push(0) ;
    vector<int>visited( n , false) ;
    visited[0] = true ;

    int level = 0 ;
    while(!q.empty()){
        int size =  q.size() ;
        while(size--) {
            int node = q.front() ;
            q.pop() ;

            if(node == n-1) {
                return level ;
            }

            for(int &nbr : adj[node]){
                if(!visited[nbr]){
                    q.push(nbr) ;
                    visited[nbr] = true ;

                }
            }
        }
        level++ ;
    }
    return level ;
}

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    unordered_map<int  ,vector<int>>adj ;
    for(int i = 0 ; i <= n-1 ; i++){
        adj[i].push_back(i+1) ;
    }
    
    vector<int>res ;
    for(auto q : queries){
        int u = q[0] ;
        int v = q[1] ;
        adj[u].push_back(v) ;
        int d = bfs(n , adj) ;
        res.push_back(d) ;
    }

    return res ;
}
 
int main(){
 
    int n = 5 ;
    vector<vector<int>> queries = {{2,4},{0,2},{0,4}} ;
    vector<int>ans = shortestDistanceAfterQueries(n , queries);
    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}