#include<bits/stdc++.h>
 
using namespace std ;

int spanningTree(int V, vector<vector<pair<int, int>>>&adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(V,0);
    // {wt,node}
    pq.push({0,0});
    int sum = 0 ;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second ;
        int wt = it.first ;
        if(vis[node]== 1) continue ;
        vis[node]=1 ;
        sum += wt ;
        for(auto &i : adj[node]){
            int adjNode = i.first;
            int edgwt = i.second;
            if(!vis[adjNode]){
                pq.push({edgwt,adjNode});
            }
        }
    }
    return sum ;
}
 
int main(){
    
    int V = 5 ;
    vector<vector<pair<int, int>>> adj(V);
    vector<vector<int>>edges = {{0,2,1},{0,1,2},{2,1,1},{2,4,2},{2,3,2},{3,4,1}};
    int m = edges.size();
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    int minimumSum = spanningTree(V,adj);

    cout << minimumSum ;
    
    return 0;
}