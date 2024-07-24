#include<bits/stdc++.h>

// Topological sort only apply for Acyclic Directed Graph
using namespace std ;

vector<int> topologicalSort(int V , vector<int>adj[]){

    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            indegree[it]++ ;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>ans ;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // node is now in your ans so you have to decrease its indegree
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return ans ;
}

 

 
int main(){

    int n = 6 ; // vertices
    int m = 6 ; // edges 
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u ,v ;
        cin >> u >> v ;
        adj[u].push_back(v);
    }
    vector<int> topoSort = topologicalSort(n,adj);

    for(int i : topoSort){
        cout << i << " ";
    }
    return 0;
}