#include<bits/stdc++.h>
 
using namespace std ;

#define P pair<int, int>

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    unordered_map<int, vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> d1(n + 1, INT_MAX);
    vector<int> d2(n + 1, INT_MAX);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 1});
    d1[1] = 0;

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        int timePassed = temp.first;
        int node = temp.second ;

        if (d2[n] != INT_MAX && node == n) { //We reached n 2nd time means it's the second minimum
            return d2[n];
        }

        int mult = timePassed / change;
        if(mult % 2 == 1) { //Red
            timePassed = change * (mult + 1); //to set green
        }

        for (auto& nbr : adj[node]) {
            if (d1[nbr] > timePassed + time) { //+time for this edge to reach nbr
                d2[nbr] = d1[nbr];
                d1[nbr] = timePassed + time;
                pq.push({timePassed + time, nbr});
            } else if (d2[nbr] > timePassed + time && d1[nbr] != timePassed + time) {
                d2[nbr] = timePassed + time;
                pq.push({timePassed + time, nbr});
            }
        }
    }
    return -1;
}
 
int main(){
    vector<vector<int>>edges = {{1,2},{1,3},{1,4},{3,4},{4,5}};

    int time = 3;
    int change = 5;
    int n = 5 ;

    int ans = secondMinimum(n,edges,time,change);
    cout << ans ;
    
    return 0;
}