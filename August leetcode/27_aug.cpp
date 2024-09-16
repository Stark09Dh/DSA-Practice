#include<bits/stdc++.h>

// This Question is Same as August 31
 
using namespace std ;

typedef pair<double,int> P ;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    unordered_map<int,vector<pair<int,double>>>adj ;
    vector<double>res(n,0) ;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        double prob = succProb[i];

        adj[u].push_back({v,prob});
        adj[v].push_back({u,prob});
    }

    priority_queue<P>pq;

    res[start_node] = 1 ;

    pq.push({1.0 , start_node});

    while(!pq.empty()){
        int node = pq.top().second ;
        double wt = pq.top().first ;

        pq.pop();

        for(auto &temp : adj[node]){
            double adjProb = temp.second ;
            int adjnode = temp.first ;

            if(res[adjnode] < wt * adjProb){
                res[adjnode] = wt * adjProb ;
                pq.push({res[adjnode],adjnode});
            }
        }
    }

    return res[end_node] ;

}
 
int main(){
 
    vector<vector<int>>edges = {{0,1},{1,2},{0,2}} ;
    int n = 3 ;
    vector<double>succProb = {0.5,0.5,0.2};
    int start = 0 ;
    int end = 2 ;

    double ans = maxProbability(n,edges,succProb,start,end);

    cout << ans ;
    
    return 0;
}