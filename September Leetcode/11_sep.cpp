#include<bits/stdc++.h>
 
using namespace std ;

int minBitFlip(int start , int goal){
    int count = 0 ;
    while(start > 0 || goal > 0){
        if((start & 1) != (goal & 1)){
            count++;
        }
        start = start >> 1 ;
        goal = goal >> 1 ;
    }
    return count ;
}
 
int main(){
 
    int start = 10 ;
    int goal = 7 ;
    int ans = minBitFlip(start , goal) ;
    cout<< ans ;
    return 0;
}