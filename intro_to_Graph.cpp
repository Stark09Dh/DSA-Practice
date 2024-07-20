#include<bits/stdc++.h>
 
using namespace std ;

vector<int>bfsTraversal(int V, vector<int>adj[]){
    vector<int>vis(V+1,0);
    vis[1] = 1 ; // mark visited to node you want to start from 
    queue<int>q ;
    q.push(1); // always push the starting Node ;
    vector<int>ans ;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(auto it : adj[temp]){
            if(!vis[it]){
                vis[it] = 1 ;
                q.push(it);
            }
        }
    }
    return ans ;

}
 
int main(){
 
    int n = 9 ; // vertices
    int m = 9 ; // edges 
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u ,v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>traversal = bfsTraversal(n,adj);
    for(int i : traversal){
        cout << i <<" ";
    }
    return 0;
}