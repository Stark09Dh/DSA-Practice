#include<bits/stdc++.h>
 
using namespace std ;

int binary(int low , int high,int n){
    
    int ans = 0 ;
    int mid = (low+high)/2 ;

    while(low <= high){
        int mid = (low+high)/2;
        if(mid*mid <= n){
            ans = mid;
            low = mid+1;
            
        }
        else{
            high = mid-1 ;
        }
    }
    return ans ;
}


// int mysqrt(int &n){
//     int low = 0 ;
//     int high = n/2 ;

// }
 
int main(){
 
    int n = 4 ;
    int sqrt = binary(0,n/2,n);
    cout << sqrt ;

    return 0;
}