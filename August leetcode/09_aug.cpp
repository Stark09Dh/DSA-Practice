#include<bits/stdc++.h>
 
using namespace std ;

bool magicSquare(vector<vector<int>>&grid,int n1 , int m1){
    vector<int>hash(10,0);

    const int magicsum = 15 ;

    for(int i=0;i<3;i++){
        for(int j =0 ;j<3;j++){
            int num = grid[n1 + i][m1 + j];
            if (num < 1 || num > 9) return false;
            hash[num]++ ;
        }
    }

    // for 1 to 9 numbers
    for(int i=1;i<10;i++){
        if(hash[i]!=1) return false ;
    }

    // for rol and col sum 
    for(int i=0;i<3;i++){
        int rowsum = 0 ;
        int colsum = 0 ;
        for(int j=0;j<3;j++){
            rowsum += grid[n1 + i][m1 + j];
            colsum += grid[n1 + j][m1 + i];
        }
        if (rowsum != magicsum || colsum != magicsum) return false;
    }

    // for daigonal 
    int sumdaig = 0 , sumdaig2 = 0 ;
    for(int i=0;i<3 ; i++){
        sumdaig += grid[n1+i][m1+i];
        sumdaig2 += grid[n1+i][m1+ 2-i];
    }

    if(sumdaig != magicsum || sumdaig2 != magicsum) return false ;

    return true ;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0 ;

    for(int i = 0 ;i<= n-3;i++){
        for(int j=0;j<= m-3;j++){
            if(magicSquare(grid,i,j)){
                ans++ ;
            }
        }
    }
    return ans ;
}
 
int main(){
 
    vector<vector<int>> grid = {{4,3,8,4},{9,5,1,9},{2,7,6,2}} ;

    int ans = numMagicSquaresInside(grid);
    cout << ans ;
    return 0;
}