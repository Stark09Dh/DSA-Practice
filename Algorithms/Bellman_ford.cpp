#include<bits/stdc++.h>
 
using namespace std ;

vector<int>Bellman_ford(vector<vector<int>>&edges,int V, int S){
    vector<int>dist(V,1e8);
    dist[S] = 0;
    for(int i=0;i<V-1;i++){
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt ;
            }
        }
    }

    // for cycle detection 
    /*
    for(auto &i : edges){
        int u = i[0];
        int v = i[1];
        int wt = i[2];

        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1} ;
        }
    }
    */

    return dist ;

}
 
int main(){
    int V = 6 ;
    vector<vector<int>>edges = {{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};
    vector<int> dist = Bellman_ford(edges,V,0);
    for(int i=0;i<dist.size();i++){
        cout << i << "->" << dist[i]<<endl;
    }
    return 0;
}