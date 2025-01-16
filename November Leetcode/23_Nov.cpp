#include<bits/stdc++.h>
 
using namespace std ;

// for rotating the matrix take transpose of that matrix

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int n  = box.size() ;
    int m = box[0].size() ;

    vector<vector<char>>ans(m , vector<char>(n)); 

    for(int i = n-1 ; i>=0 ; i--){
        int l = 0 , r = 0 ;
        while(r < m){
            if(box[i][l] == '#' && box[i][r] == '.'){
                swap(box[i][l] , box[i][r]);
                l++ ;
            }
            else if(box[i][l] =='.' && box[l][r] =='#'){
                l = r ;
            }
            else if(box[i][r] == '*'){
                l = r+1 ;
            }
            r++ ;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans[j][n-1-i] = box[i][j];
        }
    }

    return ans ;
   
}
 
int main(){
 
    vector<vector<char>>box = {{'#','#','*','.','*','.'},
              {'#','#','#','*','.','.'},
              {'#','#','#','.','#','.'}}
;

    vector<vector<char>> ans =   rotateTheBox(box) ;

    for(vector<char> v : ans){
        for(auto i : v) {
            cout << i << ' ';
        }
        cout << endl ;
    }
    return 0;
}