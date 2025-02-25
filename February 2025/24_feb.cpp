#include<bits/stdc++.h>
 
using namespace std ;

bool dfs(int src , int prev , int time , unordered_map<int ,int>&bob_time,unordered_map<int , vector<int> > &adj){
    if(src == 0) {
        bob_time[src] = time ;
        return true;
    }

    for(auto nbr : adj[src]){
        if(nbr == prev){
            continue ;
        }
        if(dfs(nbr , src , time + 1 , bob_time , adj)){
            bob_time[src] = time ;
            return true ;
        }
    }
    return false ;
}



int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    unordered_map<int , vector<int> > adj ;

    int res = INT_MIN  ;

    for(auto &i : edges){
        int u = i[0] ;
        int v = i[1] ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    unordered_map< int , int > bob_time ;

    dfs(bob , -1 , 0 , bob_time , adj) ;

    queue<tuple<int , int , int , int >> q ; // {node ,time , parent , total profit}

    q.push({0 ,0 , -1 ,amount[0]}) ;

    while(!q.empty()){
        auto[node , time , parent , profit] = q.front() ;
        q.pop() ;
        
        for(int nbr : adj[node]){
            if(nbr == parent) continue ;

            int nbr_profit = amount[nbr] ; // amount at that node
            int nbr_time = time + 1 ; // time took to reach that node

            if(bob_time.find(nbr) != bob_time.end()){
                if(nbr_time > bob_time[nbr]){
                    nbr_profit = 0 ;
                }
                if(nbr_time == bob_time[nbr]){
                    nbr_profit = nbr_profit / 2 ;
                }
            }

            q.push({nbr , nbr_time , node, profit + nbr_profit});

            if(adj[nbr].size() == 1){
                res = max(res , profit + nbr_profit) ;
            }
        }
    }
    return res ;
}
 
int main(){
 
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6} ;

    cout << mostProfitablePath(edges , bob , amount) ;


    return 0;
}