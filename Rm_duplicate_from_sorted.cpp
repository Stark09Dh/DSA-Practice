#include<bits/stdc++.h>
using namespace std ;

vector<int> sol(int n , vector<int>&arr){
    vector<int>res ;
    int size = 1 ;
    for(int i= 1;i<n;i++){
        if(arr[i]!=arr[i-1]) {
            size += 1;                  // For Computing Size
            res.push_back(arr[i-1]);  // For Storing unique elements
        }
    }
    res.push_back(arr[n-1]);
    return res;
}
int sol2(int n , vector<int>&arr){
    int size = 1 ;
    for(int i= 1;i<n;i++){
        if(arr[i]!=arr[i-1]) {
            size += 1;                  // For Computing Size
        }
    }
    
    return size;
}

// Updating in Same array 

int sol(vector<int>&arr){
    int n= arr.size();
    int k = 1 ;
    for(int i=1;i<n;i++){
        if(arr[i] != arr[i-1]){
            arr[k++] = arr[i];
        }
    }
    return k ; 
}



int main(){
    int n = 10 ;
    vector<int>arr = {0,0,1,1,1,2,2,3,3,4};
    //vector<int> sizeafterRm = sol(n,arr);
    int size = sol2(n,arr);
    // for(int i:sizeafterRm){
    //     cout << i << " ";
    // }
    cout << size ; 
}