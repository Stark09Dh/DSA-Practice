#include<bits/stdc++.h>
 
using namespace std ;

// Brute Force TC = O(N*N)

int sol2(vector<int>&arr){
    int n= arr.size();
    for(int i=0;i<n;i++){
        int cnt = 0 ;
        for(int j= 0;j<n;j++){
            if(arr[j] == arr[i]) cnt++;
        }
        if(cnt > n/2) return arr[i];
    }
}

// using hashing TC = O(n) SC = O(n)
int sol(vector<int>&arr){
    int n = arr.size();
    vector<int>hash(n+1,0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    } 
    int ans = 0;
    for(int i=0;i<hash.size();i++){
        ans = max(ans,hash[i]);
    }
    int res = 0 ;
    for(int i=0;i<hash.size();i++){
        if(hash[i] == ans){
            res = i ;
        }
    }
    return res;
    
}

// // using Map
int sol3(vector<int>&arr){
    int n = arr.size();
    map<int,int>amap;

    for(int i=0;i<n;i++){
        amap[arr[i]]++;
    }

    for(auto it : amap){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1 ;

    
}

// Optimal Approach - using Moore's Voting Algoritm
int sol4(vector<int>&arr){
    int n =arr.size();
    int cnt = 0 ;
    int el;
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt = 1 ;
            el = arr[i];
        }
        else if(arr[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int temp = 0 ;
    for(int i=0;i<n;i++){
        if(arr[i] == el) temp++;
    }
    if(temp>n/2) return el;
    return -1 ;
}

 
int main(){

    vector<int>arr = {2,2,1,1,1,2,2};
    int ans = sol4(arr);
    cout << ans ;
    
    return 0;
}