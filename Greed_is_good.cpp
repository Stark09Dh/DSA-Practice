#include<bits/stdc++.h>
 
using namespace std ;

int score(const array<unsigned, 5>& dice) {
    
    vector<int>freq(7 ,0) ;

    for(int i = 0 ; i < 5 ; i++ ){
        freq[dice[i]]++ ;
    }
    int sum= 0 ;
    sum += (freq[1]/3)*1000 ;
    freq[1] %= 3 ;
    sum += freq[1] * 100 ;

    sum += (freq[5]/3)*500;
    freq[5] %= 3 ;
    sum += freq[5] * 50 ;

    for(int i = 2 ;i<=6;i++){
        if(freq[i] >= 3){
            sum += i* 100 ;
        }

    }
    return sum ;
    
}

 
int main(){
 
    array<unsigned , 5> dice = {1,2,3,4,6} ;
    int ans = score(dice);
    cout << ans ;

    return 0;
}