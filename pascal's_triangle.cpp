#include<bits/stdc++.h>
 
using namespace std ;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>>ans ;

    for (int i = 0; i < numRows; i++){
        vector<int>rows(i+1,1) ;

        for(int j=1;j<i;j++){
            rows[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(rows) ;

    }
    return ans ;  
}
 
int main(){
 
    int n = 5 ;

    vector<vector<int>>ans = generate(n) ;

    for(auto &row : ans){
        for(int val : row){

            cout << val <<" " ;
        }
    }

    return 0;
}

/*
n = 5 

0         1
1        1,1
2       1,2,1
3      1,3,3,1
4     1,4,6,4,1


*/