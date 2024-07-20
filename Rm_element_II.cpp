#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&arr){
    int n = arr.size();
    if(n<=2) return n ;
    int k = 2 ;
    for(int i=2;i<n;i++){
        if(arr[i] != arr[k-2]){
            arr[k++] = arr[i];
        }
    }
    return k ;
}
 
int main(){
 
    vector<int>arr = {0,0,1,1,1,1,2,3,3};
    int res = sol(arr);
    for(int i=0;i<res;i++){
        cout << arr[i] << " ";
    }
    return 0;
}