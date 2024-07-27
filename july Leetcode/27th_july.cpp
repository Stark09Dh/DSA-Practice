// Pretty Good Problem 
// 2976. Minimum Cost to Convert String I


#include<bits/stdc++.h>

using namespace std ;

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    int n = 26;

    int  INF = INT_MAX ;

    vector<vector<int>>matrix(n,vector<int>(n,INF));

    
    for (int i = 0; i < original.size(); i++) {
        int u = original[i] - 'a';
        int v = changed[i] - 'a';
        matrix[u][v] = min(matrix[u][v],cost[i]);
    }
    for(int i=0;i<n;i++){
        matrix[i][i] = 0 ;
    }

    
    int i,j,k;
    for (k = 0; k < n; k++) {
        
        for (i = 0; i < n; i++) {
            
            for (j = 0; j < n; j++) {
                
                if (matrix[i][k] < INF && matrix[k][j] < INF)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    long long ans = 0 ;
    int m = source.length();
    for(int i=0;i<m;i++){
        int src = source[i] -'a';
        int tar = target[i] - 'a';
        if(matrix[src][tar] >= INF){
            return -1 ;
        }
        ans += matrix[src][tar];
    }
    return ans ;

}
 
int main(){
    
    string source = "abcd" ;
    string target = "acbe" ;
    vector<char>original = {'a','b','c','c','e','d'};
    vector<char>changed = {'b','c','b','e','b','e'};
    vector<int>cost = {2,5,5,1,2,20} ;

    long long ans = minimumCost(source,target,original,changed,cost);

    cout << ans <<endl;
    
    return 0;
}

//  , , cost = 