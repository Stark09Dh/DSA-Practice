#include<bits/stdc++.h>
 
using namespace std ;

bool canArrange(vector<int>& arr, int k) {
    vector<int>mp(k,0);
    int n = arr.size();

    for(int i=0;i<n;i++){
        int rem = (arr[i] % k + k) % k ;
        mp[rem]++ ;
    }

    if(mp[0] % 2 != 0){
        return false ;
    }

    for(int rem= 1 ;rem <= k/2 ; rem++){
        int counterPart = k - rem ;
        if(mp[counterPart] != mp[rem]){
            return false ;
        }
    }
    return true ;

}
 
int main(){
 
    vector<int> arr = {1,2,3,4,5,10,6,7,8,9}; 
    int k = 5;
    cout << (canArrange(arr,k)) ? "True" : "false" ;
    return 0;
}