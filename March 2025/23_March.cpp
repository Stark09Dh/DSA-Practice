#include<bits/stdc++.h>
 
using namespace std ;


 
class Solution{
public:

    const int mod = 1e9 + 7 ;
    typedef pair<long ,long> P ;
    typedef long long ll ;

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int , list<pair<int,int>>>adj ;
        for(auto i : roads){
            int u = i[0] ;
            int v = i[1] ;
            int w = i[2] ;
            adj[u].push_back({v,w}) ;
            adj[v].push_back({u,w}) ;
        }
        priority_queue<P, vector<P>, greater<P>> pq ;
        vector<ll> res(n , LLONG_MAX) ;
        vector<ll> path(n , 0 );
        res[0] = 0 ;
        path[0] = 1 ;
        pq.push({0,0}) ; // node , time ;

        while(!pq.empty()){
            pair<int,int> temp = pq.top() ;
            ll currTime = temp.first;
            ll currNode = temp.second ;
            pq.pop() ;

            for(auto nbr :adj[currNode]){
                ll nbr_node = nbr.first ;
                ll nbr_time = nbr.second ;
                if(res[nbr_node] > nbr_time + currTime){
                    res[nbr_node] = nbr_time + currTime ;
                    pq.push({ res[nbr_node],nbr_node ,}) ;
                    path[nbr_node] = path[currNode] ;
                }
                else if(nbr_time + currTime == res[nbr_node]){
                    path[nbr_node] = (path[nbr_node] + path[currNode])%mod;
                }
            }
        }
        return path[n-1] ;
    }
};
int main(){
 
    Solution sol ;
    int  n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}} ;
    cout << sol.countPaths(n , roads);
    
    return 0;
}