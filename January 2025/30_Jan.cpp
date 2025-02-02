#include<bits/stdc++.h>
 
using namespace std ;

bool Bipartite(unordered_map<int,vector<int>>&adj , int curr , vector<int>&color , int currColor){
    color[curr] = currColor ;

    for(int ngbr : adj[curr]){
        if(color[ngbr] == color[curr]){
            return false ;
        }
        if(color[ngbr] == -1){
            if(Bipartite(adj , ngbr , color , 1-currColor)==false){
                return false ;
            }
        }
    }
    return true ;

}

int dfs(unordered_map<int,vector<int>>&adj , int currNode , int n){
    vector<bool>visited(n+1 , false) ;
    queue<int>q ;
    q.push(currNode) ;
    visited[currNode] = true ;

    int level = 1 ;

    while(!q.empty()){
        int size = q.size() ;

        while(size--){
            int curr = q.front() ;
            q.pop();

            for(int &ngbr : adj[curr]){
                if(visited[ngbr]) continue; 

                q.push(ngbr);
                visited[ngbr] = true ;
            }
        }
        level++ ;
    }
    return level-1 ;
}

int getMax(unordered_map<int,vector<int>>&adj,int curr , vector<bool>&visited , vector<int>&level){
    int maxGrp = level[curr] ;
    visited[curr]  = true ;

    for(int &ngbr : adj[curr]){
        if(!visited[ngbr]){
            maxGrp = max(maxGrp ,getMax(adj,ngbr,visited,level) );
        }
    }
    return maxGrp ;
}


int magnificentSets(int n, vector<vector<int>>& edges) {
    unordered_map<int,vector<int>>adj ;

    for(auto i : edges){
        int u = i[0] ;
        int v = i[1] ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    // Bipartite check 
    vector<int>color(n+1 ,-1);
    for(int node = 1 ; node <= n ; node++){
        if(color[node] == -1){
            if(Bipartite(adj,node,color,1) == false){
                return -1 ;
            }
        }
    } 
    vector<int>level(n+1 , 0) ;

    for(int node = 1 ; node <= n ; node++){
        level[node] = dfs(adj , node , n) ;
    }

    int maxGroup =  0;
    vector<bool>visited(n+1 , false);
    for(int node = 1 ; node <= n ; node++){
        if(!visited[node]){
            maxGroup += getMax(adj , node , visited , level);
        }
    }

    return maxGroup ;
}

 
int main(){
    int n = 6 ;
    vector<vector<int>> edges = {{1,2},{1,4},{1,5},{2,6},{2,3},{4,6}} ;
    int ans = magnificentSets(n , edges) ;
    cout << ans ;
    return 0;
}