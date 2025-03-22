#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:

    void  dfs(int node ,int &v , int &e, unordered_map<int , vector<int> > &adj , vector<bool>&visited){
        visited[node] =true ;
        v++ ;
        e += adj[node].size() ;

        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                dfs(nbr , v , e , adj , visited) ;
            }
        }
        
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int> > adj ;
        for(auto &edge : edges ){
            int u = edge[0] ;
            int v = edge[1] ;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        vector<bool>visited(n ,false) ;
        
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                int v = 0  , e = 0 ;
                dfs(i, v, e , adj , visited) ;
                e /= 2 ;
                int total_edge = (v*(v-1)) / 2 ;
                if(total_edge == e) ans++ ;
            } 
        }
        return ans ;
    }
};
int main(){
 
    Solution sol ;
    int n = 6 ; 
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}} ;
    cout << sol.countCompleteComponents(n , edges) ;
    

    return 0;
}