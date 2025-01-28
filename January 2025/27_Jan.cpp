#include<bits/stdc++.h>
 
using namespace std ;

// Brute Force
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    unordered_map<int , vector<int>>mp ;

    for(int i = 0 ; i < prerequisites.size() ; i++){
        mp[prerequisites[i][0]].push_back(prerequisites[i][1]) ;
    }
    

    int n = queries.size() ;

    vector<bool>ans(n,false) ;

    for(int i = 0 ; i < n ; i++){

        queue<int>q ;
        unordered_set<int> visited; 
        q.push(queries[i][0] );
        visited.insert(queries[i][0]) ;

        while(!q.empty()){
            int f = q.front() ;
            
            q.pop();

            if(f == queries[i][1]){
                ans[i] = true ; 
                break ;
            }

            if(mp.find(f) != mp.end()){
                for (int next : mp[f]) {
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            } 
        }

    }
    return ans ;
       
}
 
int main(){
 
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,2},{1,0},{2,0}} , queries = {{1,0},{1,2}};
    vector<bool>ans = checkIfPrerequisite(numCourses , prerequisites,queries) ;
    for(auto i : ans ){
        cout << i << " ";
    }
    return 0;
}