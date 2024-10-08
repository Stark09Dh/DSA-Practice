#include<bits/stdc++.h>
 
using namespace std ;

int minSwaps(string s) {
    int swaps = 0 ;
    for(char &ch : s){
        if(ch == '['){
            swaps++;
        }
        else if(swaps != 0){
            swaps--;
        }
    }
    return (swaps+1)/2 ;
}
 
int main(){
 
    string s = "]]][[[" ;
    cout << minSwaps(s);
    return 0;
}