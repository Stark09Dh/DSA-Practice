#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int , vector<pair<int,int>>> adj;

        for(auto i : redEdges){
            int u = i[0] ;
            int v = i[1] ;
            adj[u].push_back({v,0}) ; // node -> {node , color - Red}
        }
        for(auto i : blueEdges){
            int u = i[0] ;
            int v = i[1] ;
            adj[u].push_back({v,1}) ; // node -> {node , color - Blue}
        }
        vector<int> ans(n , -1) ;
        ans[0] = 0 ;
        queue<pair<int,int>> q ;// [node , prev_color]
        q.push({0,0}) ;// [node , Red]
        q.push({0,1}) ; // [node, Blue]

        vector<vector<int>>dist(n , vector<int>(2,INT_MAX)) ;
        dist[0][0] = 0 ;
        dist[0][1] = 0 ;

        while(!q.empty()){
            int node = q.front().first ;
            int color = q.front().second ;
            q.pop() ;
            for(auto nbr : adj[node]){
                int nbr_node = nbr.first ;
                int nbr_color = nbr.second ;
                if(dist[nbr_node][nbr_color] == INT_MAX && color != nbr_color){
                    dist[nbr_node][nbr_color] = 1 + dist[node][color] ;
                    q.push(nbr) ;
                }
            }
        }

        for(int i = 0 ; i <n ; i++){
            int minDist = min(dist[i][0] , dist[i][1] );
            if(minDist != INT_MAX){
                ans[i] = minDist;
            }
        }
        return ans ;  
    }
} ;

int main(){
    int n = 5 ;
    vector<vector<int>>redEdges = {{0,1},{1,2},{2,3},{3,4}} ;
    vector<vector<int>> blueEdges = {{1,2},{2,3},{3,1}} ;
    Solution sol ;
    vector<int> ans =  sol.shortestAlternatingPaths(n , redEdges , blueEdges ) ;

    for(int i : ans) {
        cout << i  << " " ;
    }
    return 0;
}