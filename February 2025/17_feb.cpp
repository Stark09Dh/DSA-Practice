#include<bits/stdc++.h>
 
using namespace std ;

int sol(unordered_map<char , int > &mp) {
    int ways = 0 ;

    for(auto &i : mp){
        if(i.second > 0){
            i.second--;
            ways += 1 + sol(mp) ;
            i.second++ ;
        }
    }
    return ways ;
}

int numTilePossibilities(string tiles) {
    unordered_map<char , int > mp ;
    for(auto &i : tiles){
        mp[i]++ ;
    }
    return sol(mp) ;
}
 
int main(){
 
    string s = "A" ;
    cout <<  numTilePossibilities(s) ;
    return 0;
}