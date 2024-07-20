#include<bits/stdc++.h>

using namespace std ;

// my thinking
int sol(vector<int>&arr, int N){
    int ans = -1 ;
    for(int i= 1;i<N;i++){
        if(arr[i]-arr[i-1] > 1){
            ans = i+1 ;
            break;
        }
    }

}
// Using Hashing 
int sol2(vector<int>&arr,int N){
    vector<int>hash(N+1,0);
    int ans = -1 ;
    for(int i=0;i<N-1;i++){
        hash[arr[i]] = 1 ;
    }
    for(int i=1;i<hash.size();i++){
        if(hash[i] == 0){
            ans = i ;
            break;
        }
    }
    return ans ;
}

// optimal - 1 using Sum
int sol3(vector<int>arr,int N){
    int Sum = (N*(N+1))/2 ;
    int sum2 = 0 ;
    for(int i=0;i<arr.size();i++){
        sum2 += arr[i];
    }
    return Sum-sum2 ;
}

int main(){
    int N = 4 ;
    vector<int>arr = {1,2,3};
    int res = sol3(arr,N);
    cout << res ;
}