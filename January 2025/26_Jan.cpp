#include<bits/stdc++.h>
 
using namespace std ;

int BFS(int start ,unordered_map<int, vector<int>>&adj, vector<bool>&visitedNodes ){
    queue<pair<int,int>>que ;
    que.push({start , 0 }) ;

    int maxDistance = 0 ;

    while(!que.empty()){
        int currNode  = que.front().first ;
        int dist = que.front().second ;
        que.pop() ;

        for(auto &nbr : adj[currNode]){
            if(!visitedNodes[nbr]){
                visitedNodes[nbr] = true ;
                que.push({nbr,dist+1}) ;
                maxDistance = max(maxDistance , dist+1) ;
            }
        }
    }
    return maxDistance ;
}

int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size() ;
    unordered_map<int, vector<int>>adj ;

    for(int i =0  ; i < n ; i++){
        int u = i ;
        int v = favorite[i] ;
        adj[v].push_back(u) ;
    }   
    int longestCycle = 0 ; 
    int happyCoupleCount = 0 ;

    vector<bool>visited(n,false) ;

    for(int i =0 ;i<n;i++){
        if(!visited[i]){
            unordered_map<int,int>mp ;

            int currNode = i ;

            int currNodeCount = 0 ;

            while(!visited[currNode]){
                visited[currNode] = true ;
                mp[currNode] = currNodeCount ;

                int nextNode = favorite[currNode] ;
                currNodeCount += 1 ;

                if(mp.count(nextNode)){
                    int cycleLength = currNodeCount - mp[nextNode] ;
                    longestCycle = max(longestCycle , cycleLength) ;

                    if(cycleLength == 2 ){
                        vector<bool>visitedNodes(n,false) ;
                        visitedNodes[currNode] = true ;
                        visitedNodes[nextNode] = true ;
                        happyCoupleCount += 2 + BFS(currNode , adj, visitedNodes) + BFS(nextNode , adj, visitedNodes) ;
                    }
                    break ;
                }
                currNode = nextNode ;
            }
        }
    }   
    return max(happyCoupleCount,longestCycle) ;
}  
 
int main(){
 
    vector<int>favorite = {2,2,1,2};
    int ans = maximumInvitations(favorite) ;
    cout << ans ;
    return 0;
}