#include<bits/stdc++.h>
 
using namespace std ;

int minimumRecolors(string blocks, int k) {
    int n = blocks.length() ;
    int l = 0  , r = 0 ;
    int Black = 0 ;
    for(;r < k ; r++){
        if(blocks[r] == 'B'){
            Black++ ;
        }
    }
    int ans = k-Black ;
    while( r < n){
        
        if(blocks[l] =='B'){
            Black--;
        }
        if(blocks[r] == 'B'){
            Black++ ;
        }
        ans = min(ans , k - Black) ;
        l++ , r++;
    }
    return ans ;
    
}
 
int main(){
 
    string blocks = "WWBBBWBBBBBWWBWWWB";
    int k = 16 ;
    cout << minimumRecolors(blocks , k );
    return 0;
}