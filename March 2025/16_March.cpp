#include<bits/stdc++.h>
 
using namespace std ;

typedef long long ll ;

bool helper(ll mid , vector<int>&ranks, int cars){
    ll count = 0 ;
    for(int i = 0 ; i < ranks.size() ; i++){
        count += sqrt(mid / ranks[i]) ;
    }
    return count >= cars ;
}


long long repairCars(vector<int>& ranks, int cars) {
    int n = ranks.size() ;
    ll l = 1 ;
    int maxR = *max_element(ranks.begin() , ranks.end()) ;
    ll  h = 1ll* maxR * cars * cars;
    ll ans = -1 ;
    while(l <= h) {
        ll mid = l + ( h - l) / 2 ;
        
        if(helper(mid , ranks, cars)){
            ans = mid ;
            h = mid - 1;

        }
        else{
            l = mid + 1 ;
        }
    }
    return ans ;

}
 
int main(){
 
    vector<int>nums = {4,2,3,1} ;
    int cars = 10 ;
    cout << repairCars(nums , cars) ;
    return 0;
}