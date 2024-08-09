
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

vector<int>dijkstra(vector<vector<int>>&edges,int V,int source){
    unordered_map<int,list<pair<int,int>>>adj ;
    int edge = edges.size();

    for(int i=0;i<edge;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>dist(V,INF);

    set<pair<int,int>> st ; // first = distance , second = node

    dist[source] = 0;
    st.insert({0,source});

    while(!st.empty()){
        auto top = *(st.begin()); // st.begin() return the iterator `*` dereference it, giving access to values 
        int nodeDistance = top.first;
        int topNode = top.second ;

        // pop the top
        st.erase(st.begin());

        for(auto &neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find({dist[neighbour.first],neighbour.first});
                // if record found, erase it
                if(record != st.end()){
                    st.erase(record);
                }
                // distance update 
                dist[neighbour.first] = nodeDistance + neighbour.second ;
                st.insert({dist[neighbour.first],neighbour.first});
            }
        }
    }
    return dist ;

}



int main()
{
    int V = 6;
    vector<vector<int>>edges = {{0,1,4},{0, 2, 4},{1,2,2},{2,3,3},{2,4,1},{2,5,6},{3,5,2},{4,5,3}};

    vector<int> dist = dijkstra(edges,V,0);

    for(int i=0;i<dist.size();i++){
        cout << i <<" -> " << dist[i] <<endl;
    }

    return 0;
}