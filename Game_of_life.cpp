#include<bits/stdc++.h>
 
using namespace std ;

bool isSafe(int x , int y , int r , int c){
    return (x>=0 && y >=0 && x < r && y < c);
}

void sol(vector<vector<int>>&mat){
    int r = mat.size();
    int c = mat[0].size();

    vector<vector<int>>temp(r,vector<int>(c,0));
    
    vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            int life = 0 ;
            for(int k=0;k<dx.size();k++){
                if(isSafe(i+dx[k],j+dy[k],r,c) && mat[i+dx[k]][j+dy[k]] ==1){
                    life++;
                }
            }
            if (mat[i][j] == 1) {
                if (life < 2 || life > 3) {
                    temp[i][j] = 0; 
                } else {
                    temp[i][j] = 1; 
                }
            } else {
                if (life == 3) {
                    temp[i][j] = 1; 
                } else {
                    temp[i][j] = 0; 
                }
            }
        }
    }
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            mat[i][j] = temp[i][j];
        }
    }
}
 
int main(){
 
    vector<vector<int>> mat = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}} ;
    sol(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}