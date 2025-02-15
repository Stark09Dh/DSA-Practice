#include<bits/stdc++.h>
 
using namespace std ;

// all number whose square upon rearranging and summing up gives the same number ;
set<int>st ={1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,
    657,675,703,756,792,909,918,945,964,990,991,999,1000
};

int punishmentNumber(int n) {
    int sum = 0 ;
    for(auto &it : st ){
        if( it <= n){
            sum += it*it ;
        }
        else{
            break ;
        }
    }   
    return sum ;
}
 
int main(){
 
    cout << punishmentNumber(37) ;
    return 0;
}