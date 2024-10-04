#include<bits/stdc++.h>
 
using namespace std ;

long long dividePlayers(vector<int>& skill) {
    int n = skill.size() ;
    int n_2 = n/2 ;
    sort(skill.begin(), skill.end()) ;
    
    long long ans = 0 ;

    int l = 0 , r = n-1 ;
    long long sum  = accumulate(skill.begin(),skill.end(),0LL);

    int tar =   sum / n_2 ;

    if(sum % n_2 != 0 ) return -1 ;
    
    while(l<=r){
        if(skill[l] + skill[r] == tar){
            ans += skill[l]*skill[r] ;
            l++,r--;
        }
        else{
            return -1 ; 
        }
    }

    return ans ;

}
 
int main(){
 
    vector<int> skills  = {1,1,2,3};
    cout << dividePlayers(skills) ;
    return 0;
}