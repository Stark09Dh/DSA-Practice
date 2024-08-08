#include<bits/stdc++.h>
 
using namespace std ;

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>>res ;
    vector<vector<int>>dirn = {{0,1},{1,0},{0,-1},{-1,0}};

    int step = 0 ;
    int dir = 0 ;

    res.push_back({rStart,cStart});

    while(res.size() < rows*cols){
        if(dir == 0 || dir == 2) step++;

        for(int st = 0 ; st<step ; st++){
            rStart += dirn[dir][0];
            cStart += dirn[dir][1];
            if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                res.push_back({rStart,cStart});
            }
        }
        dir = (dir+1)%4;
    }
    return res ;

}
 
int main(){
 
    int rows = 1, cols = 4, rStart = 0, cStart = 0 ;
    vector<vector<int>>ans = spiralMatrixIII(rows,cols,rStart,cStart);

    for(auto &i : ans){
        cout << i[0] <<" "<<i[1] <<endl ;
    }
    return 0;
}