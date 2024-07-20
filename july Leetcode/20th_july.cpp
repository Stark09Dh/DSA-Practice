#include<bits/stdc++.h>
 
using namespace std ;

vector<vector<int>>restoreMatrix(vector<int>& rowSum, vector<int>& colSum){
    int n= rowSum.size();
    int m = colSum.size();
    vector<vector<int>>ans(n,vector<int>(m,0));

    int i=0,j=0;
    while(i<n && j<m){
        ans[i][j] = min(rowSum[i],colSum[j]);
        rowSum[i] -= ans[i][j] ;
        colSum[j] -= ans[i][j];

        if(rowSum[i] == 0 ) i++ ;

        if(colSum[j] == 0) j++ ;
    }
    return ans ;
}
 
int main(){
    vector<int>rowSum = {3,8};
    vector<int>colSum = {4,7};

    vector<vector<int>>res = restoreMatrix(rowSum,colSum);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl ;
    }
    return 0;
}