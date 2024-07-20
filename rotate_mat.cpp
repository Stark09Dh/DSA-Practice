#include<bits/stdc++.h>
 
using namespace std ;

 
void sol(vector<vector<int>>&mat){
    int n= mat.size();
    int m = mat[0].size();
    vector<vector<int>>temp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j] = mat[j][i];
        }
    }
    for(int i=0;i<n;i++){
        int l =0 , r = m-1;
        while(l<r){
            int fake = temp[i][l];
            temp[i][l] = temp[i][r];
            temp[i][r] = fake;
            l++,r--;
        }
    }
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            mat[i][j] = temp[i][j] ;
        }
        
    }


}


int main(){
 
    vector<vector<int>>mat = {{1,2,3},{4,5,6},{7,8,9}};
    sol(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}