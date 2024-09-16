#include<bits/stdc++.h>
 
using namespace std ;

vector<int> candyStore(int candies[], int N, int K){
    // Write Your Code here

    sort(candies,candies+N);

    
    int minCost = 0;

    for(int i=0,j=N-1 ; i<=j ; i++){
        minCost += candies[i];
        j -= K;
    }


    int maxCost = 0;

    for(int i=N-1,j=0 ; i>=j ; i--){
        maxCost += candies[i];
        j += K;
    }
    
    
    return {minCost , maxCost} ;

}
 
int main(){
    int N = 10 ;
    int K = 1 ;
    int candies[N] = {1,2,3,4,5,6,7,8,9,10};

    vector<int>ans  = candyStore(candies,N,K);

    cout << ans[0] << " " <<ans[1] ;
    
    return 0;
}