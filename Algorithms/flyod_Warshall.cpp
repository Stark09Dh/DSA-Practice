
#include <bits/stdc++.h>
using namespace std;

#define INF 99999 

void floyd_Warshall(vector<vector<int>>&cost){
    int n = cost.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cost[i][j] = min(cost[i][j] , cost[i][k]+cost[k][j]);
            }
        }
    }
}


int main()
{
    int V = 6;
    vector<vector<int>>edges = {{0,1,4},{0, 2, 4},{1,2,2},{2,3,3},{2,4,1},{2,5,6},{3,5,2},{4,5,3}};

    vector<vector<int>>cost(V,vector<int>(V,INF));

    for(int i=0;i<V;i++){
        cost[i][i] = 0 ;
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            cost[u][v] = w ;
        }
    }

    floyd_Warshall(cost);

    for(int i=0;i<V;i++){
        for(int j= 0;j<V;j++){
            if(cost[i][j] == INF){
                cout << -1 << " ";
            }
            else{
                cout << cost[i][j] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}