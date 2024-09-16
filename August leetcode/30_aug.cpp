#include<bits/stdc++.h>
 
using namespace std ;

typedef long long ll ;
const int LARGE_VAL = 2e9 ;

typedef pair<long ,long > P ;

ll Dijkstra(vector<vector<int>>&edges,int n , int source , int destination){
    unordered_map<ll ,vector<pair<ll,ll>>>adj ;

    for(vector<int>&edge : edges){
        if(edge[2] != -1){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }

    priority_queue<P , vector<P>,greater<P>> pq;

    vector<ll>result(n,INT_MAX);
    vector<bool>visited(n,false);

    result[source] = 0 ;
    pq.push({0,source});

    while(!pq.empty()){
        ll currDist = pq.top().first ;
        ll currNode = pq.top().second ;

        pq.pop();

        if(visited[currNode] == true){
            continue;
        }
        visited[currNode] = true ;

        for(auto &[ngb , wt] : adj[currNode]){
            if(result[ngb] > currDist+wt){
                result[ngb] = currDist + wt ;
                pq.push({result[ngb],ngb});
            }
        }
    }

    return result[destination];
}


vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
    ll currShortest = Dijkstra(edges ,n ,source ,destination);

    if(currShortest < target){
        return {};
    }

    bool  matchTrarget  = (currShortest == target);
    // if(matchTrarget == true ){
    //     for(vector<int> &edge : edges){
    //         if(edge[2] == -1){
    //             edge[2] = LARGE_VAL;
    //         }
    //     }

    //     return edges ;
    // }

    for(vector<int>&edge : edges){
        if(edge[2] == -1){
            edge[2] = (matchTrarget==true) ? LARGE_VAL : 1 ;

            if(matchTrarget != true){
                ll newshortest = Dijkstra(edges , n , source,destination);

                if(newshortest <= target){
                    matchTrarget = true ;
                    edge[2] += (target - newshortest) ;
                }
            }

        }
    }

    if(matchTrarget == false){
        return {};
    }

    return edges ;
}

int main(){
    int n = 5 ;
    vector<vector<int>>edges = {{4,1,-1},{2,0,-1},{0,3,-1},{4,3,-1}} ;
    int source = 0;
    int destination = 1;
    int target = 5;
    vector<vector<int>>ans = modifiedGraphEdges(n,edges,source,destination,target);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout << ans [i][j] << " ";
        }
        cout << endl ;
    }
    return 0;
}