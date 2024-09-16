#include<bits/stdc++.h>
 
using namespace std ;

int n ;

int t[2][101][101];

int alice(vector<int>&piles, int person, int i, int M){
    if(i >= n) return 0 ;

    if(t[person][i][M] != -1) return t[person][i][M] ;

    int stones = 0 ; 


    int result = (person) ? -1 : INT_MAX ;

    for(int x = 1 ; x <= min(2*M , n-i); x++){
        stones += piles[i+x-1];

        if(person){
            result = max(result, stones+alice(piles,0,i+x,max(M,x)));
        }
        else{
            result = min(result,alice(piles,1,i+x,max(M,x)));
        }
    }

    return t[person][i][M] = result ;
}

int stoneGameII(vector<int>&piles){
    n = piles.size();
    memset(t,-1,sizeof(t));

    return alice(piles,1,0,1);
}
 
int main(){
 
    vector<int>piles = {2,7,9,4,4};

    int ans = stoneGameII(piles);
    cout << ans ;
    return 0;
}