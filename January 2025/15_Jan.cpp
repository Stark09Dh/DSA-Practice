#include<bits/stdc++.h>
 
using namespace std ;

bool isSet(int &x , int bit){
    return x & (1 << bit) ;
}

bool setBit(int &x , int bit){
    return  x |= (1 << bit) ;
}
bool unsetBit(int &x , int bit ){
    return x &= ~(1 << bit) ;
}

int minimizeXor(int num1, int num2) {
    int x = num1 ;
    int setBits = __builtin_popcount(num2) ;
    int currSetBits = __builtin_popcount(x) ;

    int bit = 0 ;
    if(currSetBits < setBits){
        while(currSetBits < setBits){
            if(!isSet(x, bit)){
                setBit(x,bit) ;
                currSetBits++ ;
            }
            bit++;
        }
    }  
    else if(currSetBits > setBits){
        while(currSetBits > setBits){
            if(isSet(x , bit)){
                unsetBit(x, bit);
                currSetBits++ ;
            }
            bit++ ;
        }
    } 
    return x ; 
}
 
int main(){
 
    int num1 = 1 , num2 = 12 ;
    int ans = minimizeXor(num1 , num2) ;
    cout << ans ;
    return 0;
}