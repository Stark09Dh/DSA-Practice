#include<bits/stdc++.h>
 
using namespace std ;
unsigned long long solution(vector<unsigned long long>& arr){
    int n = arr.size() ;
    if(n < 2) return arr[n-1] ;
    unsigned long long gcd = LONG_MAX;
    for(int i = 1 ; i<n ; i++){
        unsigned long long temp = __gcd(arr[i-1] , arr[i]) ;
        gcd = min(gcd , temp) ;

    }
    return gcd*n ;
}
 
int main(){
 
    vector<unsigned long long>arr = {118012629, 239832117, 308355579, 53296026, 274093848, 194149809, 258866412, 178922373, 7613718, 319776156, 361651605};
    cout << solution(arr) ;
    return 0;
}

