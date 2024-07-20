#include<bits/stdc++.h>
 
using namespace std ;

int sol(vector<int>&arr){
    int n= arr.size();
    if(n<=1) return n ;
    int jump = 0;
    int l = 0;
    int r = 0 ;
    while(r < n-1){
        int far = 0 ;
        for(int i = l;i<=r;i++){
            far = max(far,i+arr[i]);
        }
        l =  r+1;
        r = far;
        jump += 1;
    }

    return jump ;
}
 
int main(){
 
    vector<int>arr = {2,3,1,1,4};
    int no_jump = sol(arr);
    cout << no_jump << " ";
    return 0;
}