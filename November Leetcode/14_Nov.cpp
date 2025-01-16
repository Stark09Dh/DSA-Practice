#include<bits/stdc++.h>
 
using namespace std ;

bool isPossible(int x , vector<int>&quantities , int n){
    for(int &product : quantities){
        n -= (product + x - 1)/x ;

        if( n < 0) return false ;
    }

    return true ;
}

int minimizedMaximum(int n , vector<int>&quantities){
    int m = quantities.size() ;

    int l = 1 ;
    int r = *max_element(quantities.begin() , quantities.end());

    int ans = 0 ;

    while(l<=r){
        int mid = l + (r - l) / 2 ;

        if(isPossible(mid , quantities , n)){
            ans = mid;
            r = mid - 1 ;
        }
        else {
            l = mid + 1 ;
        }
    }
    return ans ;
}
 
int main(){
 
    int n = 7 ;
    vector<int>quantities = {15,10,10} ;
    cout << minimizedMaximum(n,quantities) ;
    return 0;
}