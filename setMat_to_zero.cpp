#include<bits/stdc++.h>
 
using namespace std ;

void sol(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    
    vector<bool>row(n,false);
    vector<bool>col(m,false);

    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j] == 0){
                row[i] = true;
                col[j] = true ;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(row[i]){
            for(int j=0;j<m;j++){
                mat[i][j] = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(col[j]){
                mat[i][j] =0;
            }
        }
    }

}
 
int main(){
 
    vector<vector<int>>mat = {{0,1,2,0},{3,4,5,2},{1,3,1,5}} ;
    sol(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}