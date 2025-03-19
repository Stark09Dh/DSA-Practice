#include<bits/stdc++.h>

// 1466 . Reorder Routes to Make All Paths Lead to the City Zero
 
using namespace std ;
 
class Solution{
public:

    void dfs(int node ,unordered_map<int , vector<pair<int,int>>>& adj, vector<bool>&visited,int &ans ){
        visited[node] = true ;

        for(auto nbr : adj[node]){
            if(!visited[nbr.first]){
                if(nbr.second == 0) ans++ ;
                dfs(nbr.first , adj , visited , ans) ;
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int , vector<pair<int,int>>> adj ;

        for(auto i : connections){
            int u = i[0] ;
            int v = i[1] ;
            adj[u].push_back({v,0})  ;// original edges marked as 0
            adj[v].push_back({u,1}) ; // fake edges marked as 1 ;
        }
        vector<bool>visited(n , false) ;
        int ans = 0 ;
        dfs(0 , adj , visited,ans) ;
        return ans ;
    }
 
};
int main(){
 
    Solution sol ;
    int n = 6  ;
    vector<vector<int>>connections =  {{0,2},{0,3},{4,1},{4,5},{5,0}} ;

    cout << sol.minReorder(n, connections) ;

    
    return 0;
}