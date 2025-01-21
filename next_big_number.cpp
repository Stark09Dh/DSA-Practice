#include<bits/stdc++.h>
 
using namespace std ;

long nextBigger(long n) {
    vector<int>temp ;
    while(n>0){
        int digit = n % 10 ;
        n /= 10 ;
        temp.push_back(digit) ;
    }
    reverse(temp.begin(), temp.end())  ;
    int size = temp.size() ;
    int i = size-2;
    while(i>=0 && temp[i] >= temp[i+1]){
        i-- ;
    }
    if(i<0) return -1 ;

    int j = size - 1 ;
    while(temp[i] >= temp[j]){
        j-- ;
    }
    swap(temp[i] , temp[j]);

    reverse(temp.begin() + i + 1 , temp.end()) ;
    

    long number = 0 ;
    for(int &i : temp){
        number = number * 10 + i ;
    }
    
    return number ;

}
 
int main(){
 
    long n = 111;
    long ans = nextBigger(n);
    cout << ans ;
    
    return 0;
}

/*
for(auto &i: temp){
    cout << i << " ";

    144 --> 414
    441 --> 414
}
*/