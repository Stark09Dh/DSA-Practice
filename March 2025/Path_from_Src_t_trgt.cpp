#include<bits/stdc++.h>
 
using namespace std ;
 
class Solution{
public:
    int n ;
    void dfs(int node , vector<vector<int>>&paths , vector<int>&path ,vector<vector<int>>& graph ){
        path.push_back(node) ;
        if(node == n-1){
            paths.push_back(path) ;
        }
        

        for(auto i : graph[node]){
            dfs(i , paths , path , graph) ;
        }

        path.pop_back() ;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size() ;
        vector<vector<int>>paths ;
        vector<int>path ;
        dfs(0 , paths , path , graph) ;
        return paths ;
    }
 
};
int main(){
    
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}} ;
    Solution sol ;
    vector<vector<int>>paths = sol.allPathsSourceTarget(graph) ;

    for(vector<int> vec : paths){
        for(int i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}